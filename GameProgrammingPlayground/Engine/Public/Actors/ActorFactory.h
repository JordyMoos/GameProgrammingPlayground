#pragma once

#include <unordered_map>
#include <string>
#include <functional>
#include "../../ThirdParty/tinyxml2.h"
#include "ActorTypes.h"


class ActorFactory
{
private:
	std::unordered_map<std::string, std::function<AbstractActorComponent*()>> componentMap;
	ActorId lastActorId;

protected:
	

public:
	ActorFactory();

	virtual bool VInit();

	StrongActorPtr CreateActor(const char* actorResource);

	//virtual StrongActorComponentPtr VCreateComponent(tinyxml2::XMLElement* data);

	
private:
	ActorId GetNextActorId()
	{
		lastActorId++;
		return lastActorId;
	}
};