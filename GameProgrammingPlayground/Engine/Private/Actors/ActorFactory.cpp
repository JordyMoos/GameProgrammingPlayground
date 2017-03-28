#include "../../Public/Actors/ActorFactory.h"
#include "../../Public/Actors/Actor.h"
#include "../../Public/Debugging/Logger.h"


ActorFactory::ActorFactory()
{
	lastActorId = INVALID_ACTOR_ID;
}


StrongActorPtr ActorFactory::CreateActor(const char* actorResource)
{
	tinyxml2::XMLDocument* root = nullptr;
	root->LoadFile(actorResource);
	if (root == nullptr)
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




	actor->PostInit();

	return actor;
}