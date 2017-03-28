#include "../../Public/Actors/ActorFactory.h"
#include "../../Public/Actors/Actor.h"
#include "../../Public/Debugging/Logger.h"


ActorFactory::ActorFactory()
{
	lastActorId = INVALID_ACTOR_ID;
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
	GAME_INFO(root->Name());
	
	for (auto element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
	{
		GAME_INFO(element->Name());
	}



	actor->PostInit();

	return actor;
}