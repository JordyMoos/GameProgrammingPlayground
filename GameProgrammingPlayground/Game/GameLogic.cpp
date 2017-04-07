
#include "GameLogic.h"
#include "../Engine/Debugging/Logger.h"
#include "../Engine/ThirdParty/tinyxml2/tinyxml2.h"
#include "../Engine/Actors/ActorFactory.h"
#include "../Engine/EventManager/Events.h"

bool GameLogic::Init()
{
	return true;
}


bool GameLogic::LoadLevel(const char* levelResource)
{
	tinyxml2::XMLDocument doc;
	auto error = doc.LoadFile(levelResource);
	if (error != 0)
	{
		GAME_ERROR("Failed to load level from resource: " + std::string(levelResource));
		return false;
	}

	auto root = doc.FirstChildElement();
	auto staticActorElement = root->FirstChildElement("StaticActors");
	for (auto actorElement = staticActorElement->FirstChildElement();
		actorElement != nullptr;
		actorElement = actorElement->NextSiblingElement())
	{
		GAME_LOGGING("\n");
		auto actorResource = actorElement->Attribute("resource");
		if (actorResource == nullptr)
		{
			GAME_ERROR("Actor does not have a resource");
			return false;
		}

		GAME_INFO("Child: " + std::string(actorElement->Name()) + " with resource: " + std::string(actorResource));
		auto actor = actorFactory->CreateActor(actorResource, actorElement);
		if (actor == nullptr)
		{
			GAME_ERROR("Could not create actor from resource: " + std::string(actorResource));
			return false;
		}

		GAME_INFO("Actor created!");
		actors.push_back(actor);

		std::shared_ptr<EvtData_New_Actor> event(new EvtData_New_Actor(actor->GetId()));
		eventManager->VQueueEvent(event);
	}

	return true;
}


void GameLogic::Update(int deltaMs)
{
	for (auto it = actors.begin(); it != actors.end(); it++)
	{
		(*it)->Update(deltaMs);
	}
}

