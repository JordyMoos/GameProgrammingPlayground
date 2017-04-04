#pragma once

#include <memory>
#include <functional>


class IEventData;

typedef unsigned long EventType;
typedef std::shared_ptr<IEventData> IEventDataPtr;
typedef std::function<IEventDataPtr()> EventListener;


class IEventManager
{
public:
	explicit IEventManager(const char* name);
	virtual ~IEventManager();


};