#pragma once

#include "AbstractActorComponent.h"


class TransformComponent : public AbstractActorComponent
{
public:
	static const char* name;

private:
	float x, y, z;

public:
	TransformComponent() : x(0), y(0), z(0) { }

	virtual bool VInit(tinyxml2::XMLDocument *data) override;

	virtual const char* VGetName() const override
	{
		return name;
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