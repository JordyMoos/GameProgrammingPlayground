#pragma once

#include "IEventManager.h"
#include "../Actors/ActorTypes.h"


class EvtData_New_Actor : public BaseEventData
{
private:
	ActorId actorId;


public:
	static const EventType eventType;
	

public:
	EvtData_New_Actor()
		: actorId(INVALID_ACTOR_ID)
	{
	}

	explicit EvtData_New_Actor(ActorId actorId)
		: actorId(actorId)
	{
	}

	virtual const EventType& VGetEventType() const override
	{
		return eventType;
	}

	virtual const char* VGetName() const override
	{
		return "EvtData_New_Actor";
	}
	
	const ActorId GetActorId() const
	{
		return actorId;
	}
};

