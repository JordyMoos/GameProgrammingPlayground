#pragma once

#include <memory>


class Actor;
class AbstractActorComponent;


typedef unsigned int ActorId;
typedef std::shared_ptr<Actor> StrongActorPtr;


typedef unsigned int ComponentId;
typedef std::shared_ptr<AbstractActorComponent> StrongActorComponentPtr;
typedef std::weak_ptr<AbstractActorComponent> WeakActorComponentPtr;

