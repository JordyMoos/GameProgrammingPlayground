#pragma once

#include <memory>


class Actor;
class AbstractActorComponent;


typedef unsigned int ActorId;
typedef std::shared_ptr<Actor> StrongActorPtr;
typedef std::weak_ptr<Actor> WeakActorPtr;


typedef unsigned int ComponentId;
typedef std::shared_ptr<AbstractActorComponent> StrongActorComponentPtr;
typedef std::weak_ptr<AbstractActorComponent> WeakActorComponentPtr;


const ActorId INVALID_ACTOR_ID = 0;
const ComponentId INVALID_COMPONENT_ID = 0;
