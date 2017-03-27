#pragma once

#include <map>
#include <memory>

#include "ActorTypes.h"
#include "AbstractActorComponent.h"


class ActorFactory;
class XMLDocument;


class Actor
{
private:
	friend class ActorFactory;


public:
	typedef std::map<ComponentId, StrongActorComponentPtr> ActorComponents;


private:
	ActorId id;
	ActorComponents components;


public:
	explicit Actor(ActorId id) : id(id)
	{
	}

	~Actor()
	{
		components.clear();
	};

	bool Init(XMLDocument* data);
	void PostInit();
	void Update(int deltaMs);

private:
	Actor() {};
};