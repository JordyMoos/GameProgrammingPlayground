//#define GLEW_STATIC

#include <stdio.h>

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include "Game/GameLogic.h"
#include "Engine/Actors/Actor.h"
#include "Engine/EventManager/EventManager.h"
#include "Engine/EventManager/Events.h"
#include "Engine/Debugging/Logger.h"


class Printer
{
public:
	void print(IEventDataPtr rawData)
	{
		std::shared_ptr<EvtData_New_Actor> data = std::static_pointer_cast<EvtData_New_Actor>(rawData);
		GAME_LOG("Printer listener got " + std::string(data->VGetName()));
	}
};


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

	Printer* printer = new Printer();
	Printer* printer2 = new Printer();
	Printer* printer3 = new Printer();

	std::shared_ptr<EventManager> eventManager(new EventManager());
	eventManager->VUpdate();
	eventManager->VAddListener(fastdelegate::MakeDelegate(printer, &Printer::print), EvtData_New_Actor::eventType);
	eventManager->VAddListener(fastdelegate::MakeDelegate(printer2, &Printer::print), EvtData_New_Actor::eventType);
	eventManager->VAddListener(fastdelegate::MakeDelegate(printer3, &Printer::print), EvtData_New_Actor::eventType);
	eventManager->VRemoveListener(fastdelegate::MakeDelegate(printer3, &Printer::print), EvtData_New_Actor::eventType);
	GAME_LOG("");
	std::shared_ptr<EvtData_New_Actor> event(new EvtData_New_Actor(1));
	eventManager->VQueueEvent(event);
	GAME_LOG("");
	eventManager->VUpdate();

	GAME_LOG("");

	ActorFactory actorFactory = ActorFactory();
	actorFactory.VInit();
	actorFactory.CreateActor("./Game/Resources/Ball.xml");

	delete printer;
	delete printer2;
	delete printer3;

	return 0;
}
