#pragma once

#include <list>
#include "../../Engine/Public/Actors/Actor.h"
#include "../../Engine/Public/Actors/ActorTypes.h"


class GameLogic
{
private:
	std::list<StrongActorPtr> actors;


public:
	bool Init();
	void Update(int deltaMs);


private:
	StrongActorPtr loadActor(const char* filename);
};