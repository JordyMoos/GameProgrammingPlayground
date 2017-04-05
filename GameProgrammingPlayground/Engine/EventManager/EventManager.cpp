#include "EventManager.h"
#include "../Debugging/Logger.h"


EventManager::EventManager()
	: activeProcessingQueue(0)
{

}


EventManager::~EventManager()
{
	
}


bool EventManager::VAddListener(const EventListener& listener, const EventType& type)
{
	// Find or create the entry
	EventListenerList& EventListenerList = eventListeners[type];
	for (auto it = EventListenerList.begin(); it != EventListenerList.end(); it++)
	{
		if (listener == (*it))
		{
			GAME_WARNING("Attempt to double register a listener");

			return false;
		}
	}

	EventListenerList.push_back(listener);

	return true;
}


bool EventManager::VRemoveListener(const EventListener& listener, const EventType& type)
{
	auto mapIt = eventListeners.find(type);
	if (mapIt == eventListeners.end())
	{
		return false;
	}

	EventListenerList& listeners = mapIt->second;
	for (auto it = listeners.begin(); it != listeners.end(); it++)
	{
		if (listener == (*it))
		{
			listeners.erase(it);
			GAME_LOG("Successfully remove a listeners");

			return true;
		}
	}

	return false;
}


bool EventManager::VTriggerEvent(const IEventDataPtr& event) const
{
	GAME_LOG("Attempting to trigger event");

	auto mapIt = eventListeners.find(event->VGetEventType());
	if (mapIt == eventListeners.end())
	{
		return false;
	}

	bool processed = false;
	const EventListenerList& listeners = mapIt->second;
	for (auto it = listeners.begin(); it != listeners.end(); it++)
	{
		GAME_LOG("Sending event" + std::string(event->VGetName()) + " to the listener");

		EventListener listener = (*it);
		listener(event);

		processed = true;
	}

	return processed;
}


bool EventManager::VQueueEvent(const IEventDataPtr& event)
{
	GAME_ASSERT(activeProcessingQueue >= 0);
	GAME_ASSERT(activeProcessingQueue < EVENTMANAGER_NUM_QUEUES);

	if (event == nullptr)
	{
		GAME_ERROR("Invalid event");
		return false;
	}

	GAME_LOG("Attempting to queue event: " + std::string(event->VGetName()));

	auto mapIt = eventListeners.find(event->VGetEventType());
	if (mapIt == eventListeners.end())
	{
		GAME_LOG("Skipping event since where are no delegates registered for " + std::string(event->VGetName()));
		return false;
	}

	queues[activeProcessingQueue].push_back(event);
	GAME_LOG("Successfully queued event: " + std::string(event->VGetName()));

	return true;
}


bool EventManager::VAbortEvent(const EventType& type, bool allOfType)
{
	GAME_ASSERT(activeProcessingQueue >= 0);
	GAME_ASSERT(activeProcessingQueue < EVENTMANAGER_NUM_QUEUES);

	auto mapIt = eventListeners.find(type);
	if (mapIt == eventListeners.end())
	{
		return false;
	}

	bool success = false;
	EventQueue& queue = queues[activeProcessingQueue];
	auto it = queue.begin();
	while (it != queue.end())
	{
		// Removing an item from the queue will invalidate the iterator
		// So have it point to the next member
		auto thisIt = it;
		++it;

		if ((*thisIt)->VGetEventType() == type)
		{
			queue.erase(thisIt);
			success = true;

			if (!allOfType)
			{
				break;
			}
		}
	}

	return success;
}


void EventManager::VUpdate()
{
	int queueToProcess = activeProcessingQueue;
	activeProcessingQueue = (activeProcessingQueue + 1) % EVENTMANAGER_NUM_QUEUES;

	GAME_LOG("Processing event queue");

	for (auto eventIt = queues[queueToProcess].begin(); eventIt != queues[queueToProcess].end(); eventIt++)
	{
		IEventDataPtr event = (*eventIt);
		const EventType& eventType = event->VGetEventType();

		auto mapIt = eventListeners.find(eventType);
		if (mapIt == eventListeners.end())
		{
			continue;
		}

		const EventListenerList& listeners = mapIt->second;
		for (auto it = listeners.begin(); it != listeners.end(); it++)
		{
			GAME_LOG("sending event " + std::string(event->VGetName()) + " to listener");

			EventListener listener = (*it);
			listener(event);
		}
	}

	queues[queueToProcess].clear();
}
