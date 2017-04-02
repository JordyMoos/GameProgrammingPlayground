#include "../../Public/Actors/ActorFactory.h"
#include "../../Public/Actors/Actor.h"
#include "../../Public/Actors/TransformComponent.h"
#include "../../Public/Debugging/Logger.h"


ActorFactory::ActorFactory()
{
	lastActorId = INVALID_ACTOR_ID;
}


bool ActorFactory::VInit()
{
	componentMap["TransformComponent"] = std::function<TransformComponent*()>([](){ return new TransformComponent(); });

	return true;
}


StrongActorPtr ActorFactory::CreateActor(const char* actorResource)
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

		GAME_INFO("New component:\n");
		GAME_LOG(component->VGetName());

		actor->AddComponent(component);
		component->SetOwner(actor);
	}

	actor->PostInit();

	return actor;
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