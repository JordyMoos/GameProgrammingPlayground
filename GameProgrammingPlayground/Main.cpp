#define GLEW_STATIC

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game/GameLogic.h"
#include "Engine/Actors/Actor.h"
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

	ActorFactory actorFactory = ActorFactory();
	actorFactory.VInit();
	actorFactory.CreateActor(".\\Game\\Resources\\Ball.xml");
	



	return 0;
}