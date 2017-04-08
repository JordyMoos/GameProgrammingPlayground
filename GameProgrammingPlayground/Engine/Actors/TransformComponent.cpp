#include "TransformComponent.h"
#include "../Debugging/Logger.h"


const char* TransformComponent::name = "TransformComponent";
const ComponentId TransformComponent::componentId = 0xE2F49EF1;


bool TransformComponent::VInit(tinyxml2::XMLElement *data)
{
	auto position = data->FirstChildElement("Position");
	if (position != nullptr)
	{
		x = position->IntAttribute("x", x);
		y = position->IntAttribute("y", y);
		z = position->IntAttribute("z", z);
	}

	return true;
}




