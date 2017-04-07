#pragma once

#include <list>
#include "../Engine/Actors/Actor.h"
#include "../Engine/Actors/ActorTypes.h"
#include "../Engine/EventManager/IEventManager.h"


class GameLogic
{
private:
	std::shared_ptr<IEventManager> eventManager;
	std::shared_ptr<ActorFactory> actorFactory;
	std::list<StrongActorPtr> actors;


public:
	GameLogic(std::shared_ptr<IEventManager> eventManager, std::shared_ptr<ActorFactory> actorFactory)
		: eventManager(eventManager), actorFactory(actorFactory)
	{

	}

	bool Init();

	bool LoadLevel(const char* levelResource);

	void Update(int deltaMs);

};