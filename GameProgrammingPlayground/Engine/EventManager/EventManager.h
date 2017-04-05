#pragma once

#include <list>
#include <map>

#include "IEventManager.h"


class EventManager : public IEventManager
{
public:
	static const unsigned int EVENTMANAGER_NUM_QUEUES = 2;


private:
	typedef std::list<EventListener> EventListenerList;
	typedef std::map<EventType, EventListenerList> EventListenerMap;
	typedef std::list<IEventDataPtr> EventQueue;


private:
	EventListenerMap eventListeners;
	EventQueue queues[EVENTMANAGER_NUM_QUEUES];
	int activeProcessingQueue;


public:
	explicit EventManager();
	virtual ~EventManager();

	virtual bool VAddListener(const EventListener& listener, const EventType& type) override;
	virtual bool VRemoveListener(const EventListener& listener, const EventType& type) override;

	virtual bool VTriggerEvent(const IEventDataPtr& event) const override;
	virtual bool VQueueEvent(const IEventDataPtr& event) override;
	
	virtual bool VAbortEvent(const EventType& type, bool allOfType) override;

	virtual void VUpdate() override;
};
