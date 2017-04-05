//#define GLEW_STATIC

#include <stdio.h>

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include "Game/GameLogic.h"
#include "Engine/Actors/Actor.h"
#include "Engine/EventManager/EventManager.h"
#include "Engine/EventManager/Events.h"
#include "Engine/Debugging/Logger.h"


int main(int argc, char* args[])
{
	printf("Hello world!\n");

	/*
	GameLogic game = GameLogic();
	game.Init();  
	game.Update(16);
	game.Update(16);
	game.Update(16);
	*/

	std::shared_ptr<EventManager> eventManager(new EventManager());
	eventManager->VUpdate();
	
	std::shared_ptr<EvtData_New_Actor> event(new EvtData_New_Actor(1));
	eventManager->VQueueEvent(event);
	eventManager->VUpdate();

	ActorFactory actorFactory = ActorFactory();
	actorFactory.VInit();
	actorFactory.CreateActor("./Game/Resources/Ball.xml");

	return 0;
}
