#pragma once

#include <list>
#include "../Engine/Actors/Actor.h"
#include "../Engine/Actors/ActorTypes.h"


class GameLogic
{
private:
	std::shared_ptr<ActorFactory> actorFactory;
	std::list<StrongActorPtr> actors;


public:
	GameLogic(std::shared_ptr<ActorFactory> actorFactory)
		: actorFactory(actorFactory)
	{

	}

	bool Init();

	bool LoadLevel(const char* filename);

	void Update(int deltaMs);


private:
	StrongActorPtr LoadActor(const char* filename);
};