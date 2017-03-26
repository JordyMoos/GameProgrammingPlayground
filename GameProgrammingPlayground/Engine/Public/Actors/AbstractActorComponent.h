#pragma once

#include <memory>
#include "ActorTypes.h"
#include "Actor.h"
#include "ActorFactory.h"


class XMLDocument;
class AbstractActorComponent;


const ComponentId INVALID_COMPONENT_ID = 0;


class AbstractActorComponent
{
private:
	friend class ActorFactory;

protected:
	StrongActorPtr owner;

public:
	virtual ~AbstractActorComponent()
	{
		owner.reset();
	}


	virtual bool VInit(XMLDocument *data) = 0;
	virtual void VPostInit() { }
	virtual void VUpdate(int deltaMs) { }
	// Used for actor modification via xml
	//virtual void VOnChange() { }

private:
	void SetOwner(StrongActorPtr owner)
	{
		this->owner = owner;
	}
};
