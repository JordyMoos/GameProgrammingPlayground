#include "ActorFactory.h"
#include "Actor.h"
#include "TransformComponent.h"
#include "../Utils/Utils.h"
#include "../Debugging/Logger.h"


ActorFactory::ActorFactory()
{
	lastActorId = INVALID_ACTOR_ID;
}


bool ActorFactory::VInit()
{
	componentMap["TransformComponent"] = std::function<TransformComponent*()>([](){ return new TransformComponent(); });

	return true;
}


StrongActorPtr ActorFactory::CreateActor(const char* actorResource, tinyxml2::XMLElement* overrides)
{
	tinyxml2::XMLDocument doc;
	auto error = doc.LoadFile(actorResource);
	if (error != 0)
	{
		GAME_ERROR("Failed to create actor from resource: " + std::string(actorResource));
		return StrongActorPtr();
	}

	ActorId nextActorId = GetNextActorId();
	StrongActorPtr actor(new Actor(nextActorId));
	if (!actor)
	{
		GAME_ERROR("Failed to initialize actor: " + std::string(actorResource));
		return StrongActorPtr();
	}

	// Add components
	auto root = doc.FirstChildElement();
	for (auto element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
	{
		StrongActorComponentPtr component = CreateComponent(element);
		if (component == nullptr)
		{
			GAME_ERROR("Failed to create component " + std::string(element->Name()));
			return StrongActorPtr();
		}

		GAME_INFO("New component:");
		GAME_LOG(component->VGetName());

		actor->AddComponent(component);
		component->SetOwner(actor);
	}

	if (overrides)
	{
		bool result = ModifyActor(actor, overrides);
		if (!result)
		{
			GAME_ERROR("Could not modify the actor");
			return StrongActorPtr();
		}
	}

	actor->PostInit();

	return actor;
}


bool ActorFactory::ModifyActor(StrongActorPtr actor, tinyxml2::XMLElement* overrides)
{
	for (auto element = overrides->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
	{
		GAME_LOG("Update: " + std::string(element->Name()));
		StrongActorComponentPtr component = MakeStrongPtr(
			actor->GetComponent<AbstractActorComponent>(element->Name())
			);

		if (component == nullptr)
		{
			// Maybe we should be able to add components?
			// Or fully replace base components with other sub components?
			GAME_ERROR("Actor does not have a " + std::string(element->Name()));
			return false;
		}

		// Override the component here

	}

	return true;
}


StrongActorComponentPtr ActorFactory::CreateComponent(tinyxml2::XMLElement* element)
{
	GAME_INFO(element->Name());

	ComponentFunctionMap::const_iterator componentIterator = componentMap.find(element->Name());
	if (componentIterator == componentMap.end())
	{
		GAME_ERROR("No component creator found with name " + std::string(element->Name()));
		return StrongActorComponentPtr();
	}

	auto component = (componentIterator->second)();

	return StrongActorComponentPtr(component);
}
