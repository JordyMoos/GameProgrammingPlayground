#pragma once

#include <map>
#include <memory>

#include "../../ThirdParty/tinyxml2.h"
#include "../Debugging/Logger.h"
#include "ActorTypes.h"
#include "AbstractActorComponent.h"


class ActorFactory;


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
		GAME_ASSERT(components.empty());
	}

	~Actor()
	{
	};

	bool Init(tinyxml2::XMLElement* data);
	void PostInit();
	void Destroy();
	void Update(int deltaMs);

	void AddComponent(StrongActorComponentPtr comonent);

	template <class ComponentType>
	std::weak_ptr<ComponentType> GetComponent(ComponentId componentId)
	{
		ActorComponents::iterator findIt = components.find(componentId);
		if (findIt == components.end())
		{
			return std::weak_ptr<ComponentType>();
		}

		StrongActorComponentPtr base(findIt->second);
		std::shared_ptr<ComponentType> sub(static_pointer_cast<ComponentType>(base));
		std::weak_ptr<ComponentType> weakSub(sub);

		return weakSub;
	}

private:
	Actor() {};
};