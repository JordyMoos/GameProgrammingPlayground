#pragma once

#include <memory>
#include "../ThirdParty/FastDelegate/FastDelegate.h"


class IEventData;

typedef unsigned long EventType;
typedef std::shared_ptr<IEventData> IEventDataPtr;
typedef fastdelegate::FastDelegate1<IEventDataPtr> EventListener;


class IEventData
{
public:
	virtual ~IEventData() {}

	virtual const EventType& VGetEventType() const = 0;
	virtual float VGetTimeStamp() const = 0;
	virtual const char* VGetName() const = 0;
};


class BaseEventData : public IEventData
{
private:
	const float timeStamp;

	
public:
	explicit BaseEventData(const float timeStamp = 0.0f) : timeStamp(timeStamp)
	{}

	virtual float VGetTimeStamp() const override
	{
		return timeStamp;
	}
};


class IEventManager
{
public:
	explicit IEventManager() {};
	virtual ~IEventManager() {};

	virtual bool VAddListener(const EventListener& listenerer, const EventType& type) = 0;
	virtual bool VRemoveListener(const EventListener& listener, const EventType& type) = 0;

	virtual bool VTriggerEvent(const IEventDataPtr& event) const = 0;
	virtual bool VQueueEvent(const IEventDataPtr& event) = 0;

	virtual bool VAbortEvent(const EventType& type, bool allOfType = false) = 0;

	virtual void VUpdate() = 0;
};