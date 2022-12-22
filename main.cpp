#include <iostream>
#include <chrono>

#include "ObjectModel/Engine.hpp"
#include "ObjectModel/Common.hpp"


int main(int argc, char * argv[])
{
	// Tensor t1(2, 3);
	// t1.at(0,0)=1;
	// t1.at(0,1)=2;
	// t1.at(0,2)=3;
	// t1.at(1,0)=4;
	// t1.at(1,1)=5;
	// t1.at(1,2)=6;
	// Logger::log(t1.toString());
	// Logger::log(t1.transposed().toString());
	// Logger::log("\n");
	// Tensor t2(3, 2);
	// t2.at(0,0)=10;
	// t2.at(0,1)=11;
	// t2.at(1,0)=20;
	// t2.at(1,1)=21;
	// t2.at(2,0)=30;
	// t2.at(2,1)=31	// Tensor t1(2, 3);
	// t1.at(0,0)=1;
	// t1.at(0,1)=2;
	// t1.at(0,2)=3;
	// t1.at(1,0)=4;
	// t1.at(1,1)=5;
	// t1.at(1,2)=6;
	// Logger::log(t1.toString());
	// Logger::log(t1.transposed().toString());
	// Logger::log("\n");
	// Tensor t2(3, 2);
	// t2.at(0,0)=10;
	// t2.at(0,1)=11;
	// t2.at(1,0)=20;
	// t2.at(1,1)=21;
	// t2.at(2,0)=30;
	// t2.at(2,1)=31;
	// Logger::log(t2.toString());
	// Logger::log(t2.transposed().toString());
	// Logger::log("\n");

	// Tensor p = t1*t2;
	// Logger::log(p.toString());

	// Logger::log(p.transposed().toString());
	// Logger::log((p*10).toString());
	// Logger::log("here");

	// p.resize(3, 1);
	// Logger::log(p.toString());

	// return 0;;
	// Logger::log(t2.toString());
	// Logger::log(t2.transposed().toString());
	// Logger::log("\n");

	// Tensor p = t1*t2;
	// Logger::log(p.toString());

	// Logger::log(p.transposed().toString());
	// Logger::log((p*10).toString());
	// Logger::log("here");

	// p.resize(3, 1);
	// Logger::log(p.toString());

	// return 0;

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

	auto start = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();
	double maxDt = 1/60.0;
	double frameTime = 1/60.0;
	double dt;

	while(engine->isRunning())
	{

	    start = std::chrono::steady_clock::now();

		while(frameTime > 0.0)
		{
			while(SDL_PollEvent(&event))
			{
				engine->processEvent(&event);
			}

			dt = std::min(frameTime, maxDt);

			engine->updatePhysics(dt);
			frameTime -= dt;
		}

		engine->renderFrame();

		end = std::chrono::steady_clock::now();
		frameTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000000.0;
	}

	Logger::log("Exiting game loop...");
	
	return 0;
}