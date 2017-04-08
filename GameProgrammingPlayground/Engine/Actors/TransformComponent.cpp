#include "TransformComponent.h"
#include "../Debugging/Logger.h"


const char* TransformComponent::name = "TransformComponent";
const ComponentId TransformComponent::componentId = 0xE2F49EF1;


bool TransformComponent::VInit(tinyxml2::XMLElement *data)
{
	tinyxml2::XMLPrinter printer;
	data->Accept(&printer);
	GAME_INFO(printer.CStr());

	auto position = data->FirstChildElement("Position");
	if (position != nullptr)
	{
		x = position->IntAttribute("x", x);
		y = position->IntAttribute("y", y);
		z = position->IntAttribute("z", z);
	}

	return true;
}


void TransformComponent::VUpdate(int deltaMs)
{
	GAME_INFO("TransformComponent X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z));
}

