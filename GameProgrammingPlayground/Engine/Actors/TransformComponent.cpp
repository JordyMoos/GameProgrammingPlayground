#include "TransformComponent.h"
#include "../Debugging/Logger.h"


const char* TransformComponent::name = "TransformComponent";
const ComponentId TransformComponent::componentId = 0xE2F49EF1;


bool TransformComponent::VInit(tinyxml2::XMLDocument *data)
{
	return true;
}




