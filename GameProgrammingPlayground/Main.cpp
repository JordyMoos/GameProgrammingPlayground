#define GLEW_STATIC

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game/public/GameLogic.h"
#include "Engine/Public/Actors/Actor.h"
#include "Engine/Public/Debugging/Logger.h"


int main(int argc, char* args[])
{
	printf("Hello world!\n");

	GameLogic game = GameLogic();
	game.Init();  
	game.Update(16);
	game.Update(16);
	game.Update(16);

	return 0;
}