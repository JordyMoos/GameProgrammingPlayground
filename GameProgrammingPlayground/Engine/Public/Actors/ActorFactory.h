#pragma once

#include "../../ThirdParty/tinyxml2.h"
#include "ActorTypes.h"


class ActorFactory
{
private:
	ActorId lastActorId;

protected:


public:
	ActorFactory();

	StrongActorPtr CreateActor(const char* actorResource);

	//virtual StrongActorComponentPtr VCreateComponent(tinyxml2::XMLElement* data);

	
private:
	ActorId GetNextActorId()
	{
		lastActorId++;
		return lastActorId;
	}
};