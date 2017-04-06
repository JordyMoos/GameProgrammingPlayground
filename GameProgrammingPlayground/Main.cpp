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

	Printer* printer = new Printer();

	std::shared_ptr<EventManager> eventManager(new EventManager());
	eventManager->VAddListener(fastdelegate::MakeDelegate(printer, &Printer::print), EvtData_New_Actor::eventType);
	std::shared_ptr<EvtData_New_Actor> event(new EvtData_New_Actor(1));
	eventManager->VQueueEvent(event);

	ActorFactory actorFactory = ActorFactory();
	actorFactory.VInit();
	actorFactory.CreateActor("./Game/Resources/Ball.xml");

	GameLogic* game = new GameLogic();
	game->Init();
	game->LoadLevel("./Game/Resources/Level.xml");
	game->Update(16);
	game->Update(16);
	game->Update(16);

	delete game;
	delete printer;

	return 0;
}
