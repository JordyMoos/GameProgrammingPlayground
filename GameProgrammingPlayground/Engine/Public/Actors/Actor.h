#pragma once

#include <map>
#include <memory>

#include "ActorTypes.h"
#include "AbstractActorComponent.h"


class ActorFactory;


class Actor
{
private:
	friend class ActorFactory;

public:
	typedef std::map<ComponentId, StrongActorComponentPtr> ActorComponents;

	ActorId id;


public:
	explicit Actor(ActorId id) : id(id)
	{
	}

	~Actor() {};


private:
	Actor() {};
};