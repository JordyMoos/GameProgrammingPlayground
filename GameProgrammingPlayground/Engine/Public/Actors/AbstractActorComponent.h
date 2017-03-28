#pragma once

#include <memory>
#include "../../ThirdParty/tinyxml2.h"
#include "ActorTypes.h"
#include "Actor.h"
#include "ActorFactory.h"


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


	virtual bool VInit(tinyxml2::XMLDocument *data) = 0;
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
