#include "Actor.h"


bool Actor::Init(tinyxml2::XMLElement* data)
{
	return true;
}


void Actor::PostInit()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		it->second->VPostInit();
	}
}


void Actor::Destroy()
{
	components.clear();
}


void Actor::Update(int deltaMs)
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		it->second->VUpdate(deltaMs);
	}
}


void Actor::AddComponent(StrongActorComponentPtr component)
{
	std::pair<ActorComponents::iterator, bool> result = components.insert(
		std::make_pair(component->VGetId(), component)
	);

	GAME_ASSERT(result.second);
}


