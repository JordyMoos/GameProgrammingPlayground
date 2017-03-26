#pragma once

#include "ActorTypes.h"


class XMLDocument;


class ActorFactory
{
private:
	ActorId lastActorId;

protected:


public:
	ActorFactory();

	StrongActorPtr CreateActor(const char* actorResource, XMLDocument* overrides);
};