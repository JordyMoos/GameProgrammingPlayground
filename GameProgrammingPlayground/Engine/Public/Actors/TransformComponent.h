#pragma once

#include "AbstractActorComponent.h"


class TransformComponent : public AbstractActorComponent
{
private:
	float x, y, z;

public:
	TransformComponent() : x(0), y(0), z(0) { }

	virtual bool VInit(tinyxml2::XMLDocument *data) override;

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