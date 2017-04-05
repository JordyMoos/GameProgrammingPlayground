#pragma once

#include <unordered_map>
#include <string>
#include <functional>
#include "../ThirdParty/tinyxml2/tinyxml2.h"
#include "ActorTypes.h"


class ActorFactory
{
private:
	typedef std::unordered_map<std::string, std::function<AbstractActorComponent*()>> ComponentFunctionMap;

private:
	ComponentFunctionMap componentMap;
	ActorId lastActorId;

protected:
	

public:
	ActorFactory();

	virtual bool VInit();

	StrongActorPtr CreateActor(const char* actorResource);

	StrongActorComponentPtr CreateComponent(tinyxml2::XMLElement* element);

	
private:
	ActorId GetNextActorId()
	{
		lastActorId++;
		return lastActorId;
	}
};