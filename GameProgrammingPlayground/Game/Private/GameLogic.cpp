
#include <stdio.h>

#include "../../Engine/ThirdParty/tinyxml2.h"
#include "../Public/GameLogic.h"
#include "../../Engine/Public/Actors/ActorFactory.h"

bool GameLogic::Init()
{
	StrongActorPtr actor = nullptr;
	actor = loadActor(".\\Game\\Resources\\Ball.xml");
	if (actor == nullptr)
	{
		return false;
	}
	actors.push_back(actor);

	return true;
}


void GameLogic::Update(int deltaMs)
{
	for (auto it = actors.begin(); it != actors.end(); it++)
	{
		(*it)->Update(deltaMs);
	}
}


StrongActorPtr GameLogic::loadActor(const char* filename)
{
	tinyxml2::XMLDocument doc;
	auto result = doc.LoadFile(filename);
	if (result != 0)
	{
		printf("Error while loading xml\n");
		return StrongActorPtr();
	}

	auto root = doc.FirstChildElement();
	printf("%s\n", root->Name());

	for (auto element = root->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
	{
		printf("\t%s\n", element->Name());
	}

	return StrongActorPtr();
}
