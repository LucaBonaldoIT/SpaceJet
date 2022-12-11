#include <iostream>
#include "ObjectModel/Logger.hpp"
#include "ObjectModel/Square.hpp"
#include "ObjectModel/Engine.hpp"
#include "ObjectModel/Tensor.hpp"

#include <SDL2/SDL.h>
#include <thread>

int main(int argc, char * argv[])
{
	Tensor t(3, 5);
	Logger::log(t.toString());

	Engine* engine = Engine::getInstance();

	// Non funziona WTF!??
	// if (engine == nullptr)
	// {
	// 	Logger::log("Error during engine!");
	// 	throw EngineNotIstantiatedException("Error during instantiation of engine"); // To-do: better msg
	// }

	Logger::log("Engine istantiated.");

	SDL_Event event;


	Logger::log("Entering game loop...");

	while(engine->isRunning())
	{

		while(SDL_PollEvent(&event))
		{
			engine->processEvent(&event);
		}

		engine->updatePhysics();

		engine->renderFrame();

	}

	Logger::log("Exiting game loop...");
	
	return 0;
}