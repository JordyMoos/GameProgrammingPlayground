#include "../../Public/Actors/TransformComponent.h"
#include "../../Public/Debugging/Logger.h"


const char* TransformComponent::name = "TransformComponent";


bool TransformComponent::VInit(tinyxml2::XMLDocument *data)
{
	return true;
}
