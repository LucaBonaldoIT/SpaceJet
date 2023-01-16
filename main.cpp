#include <iostream>
#include <chrono>

#include "ObjectModel/Engine.hpp"
#include "ObjectModel/Common.hpp"


int main(int argc, char * argv[])
{
	Engine* engine = Engine::getInstance();

	Logger::log("Engine istantiated.");
	SDL_Event event;
	Logger::log("Entering game loop...");

	auto start = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();
	double maxDt = 1/60.0;
	double frameTime = 1/60.0;
	double dt;

	while(engine->isRunning())
	{

	    start = std::chrono::steady_clock::now();

		while(SDL_PollEvent(&event))
		{
			engine->processEvent(&event);
		}

		// Update physics multiple times per frame while there's still time
		while(frameTime > 0.0)
		{
			// Upper bound for delta time
			dt = std::min(frameTime, maxDt);

			// 
			switch (engine->getCurrentGameState())
			{
				case GameState::GameMainMenu:
					break;


				case GameState::GameRunning:
					engine->updatePhysics(dt);
					break;

				case GameState::GamePaused:

					break;
			}



			frameTime -= dt;
		}

		engine->renderFrame();

		end = std::chrono::steady_clock::now();
		frameTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000000.0;	// Normalize in seconds
	}

	Logger::log("Exiting game loop...");
	
	return 0;
}