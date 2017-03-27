#include "../Public/GameLogic.h"

bool GameLogic::Init()
{
	StrongActorPtr actor(new Actor(1));
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