#pragma once

#include "AbstractActorComponent.h"


class TransformComponent : public AbstractActorComponent
{
public:
	static const char* name;
	static const ComponentId componentId;

private:
	float x, y, z;

public:
	TransformComponent() : x(0), y(0), z(0) { }

	virtual bool VInit(tinyxml2::XMLElement *data) override;

	virtual const char* VGetName() const override
	{
		return name;
	}

	virtual ComponentId VGetId() const override
	{
		return componentId;
	}

	float getX() const
	{
		return x;
	}

	float getY() const
	{
		return y;
	}

	float getZ() const
	{
		return z;
	}
};