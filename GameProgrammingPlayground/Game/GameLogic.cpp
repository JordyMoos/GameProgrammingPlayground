
#include "../Engine/Debugging/Logger.h"
#include "../Engine/ThirdParty/tinyxml2/tinyxml2.h"
#include "GameLogic.h"
#include "../Engine/Actors/ActorFactory.h"

bool GameLogic::Init()
{
	StrongActorPtr actor = nullptr;
	actor = LoadActor(".\\Game\\Resources\\Ball.xml");
	if (actor == nullptr)
	{
		return false;
	}
	actors.push_back(actor);

	return true;
}


bool GameLogic::LoadLevel(const char* filename)
{
	tinyxml2::XMLDocument doc;
	auto loaded = doc.LoadFile(filename);
	if (loaded != 0)
	{
		
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


StrongActorPtr GameLogic::LoadActor(const char* filename)
{
	tinyxml2::XMLDocument doc;
	auto result = doc.LoadFile(filename);
	if (result != 0)
	{
		GAME_ERROR("Error while loading xml");
		return StrongActorPtr();
	}

	auto root = doc.FirstChildElement();
	GAME_LOG(root->Name());

	for (auto element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
	{
		GAME_LOG(element->Name());
	}

	return StrongActorPtr();
}
