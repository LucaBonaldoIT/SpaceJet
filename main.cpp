#include <iostream>
#include "ObjectModel/Logger.hpp"
#include "ObjectModel/Square.hpp"
#include "ObjectModel/Engine.hpp"
#include "ObjectModel/Tensor.hpp"
#include "ObjectModel/Vector3d.hpp"
#include "ObjectModel/Vector2d.hpp"

#include <SDL2/SDL.h>
#include <thread>

int main(int argc, char * argv[])
{
	Tensor t1(2, 3);
	t1.at(0,0)=1;
	t1.at(0,1)=2;
	t1.at(0,2)=3;
	t1.at(1,0)=4;
	t1.at(1,1)=5;
	t1.at(1,2)=6;
	Logger::log(t1.toString());
	Tensor t2(3, 2);
	t2.at(0,0)=10;
	t2.at(0,1)=11;
	t2.at(1,0)=20;
	t2.at(1,1)=21;
	t2.at(2,0)=30;
	t2.at(2,1)=31;
	Logger::log(t2.toString());
	Tensor p = t1*t2;
	Logger::log(p.toString());

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