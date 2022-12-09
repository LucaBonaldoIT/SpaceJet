#include <iostream>
#include "ObjectModel/Space.hpp"
#include "ObjectModel/Square.hpp"
#include "ObjectModel/Engine.hpp"

#include <SDL2/SDL.h>
#include <thread>


void loop()
{



}

int main(int argc, char * argv[])
{

	Engine engine = Engine();
	SDL_Log("Engine istantiated.");

	SDL_Event* event;

	
	SDL_Log("Engine is runnning.");
	while(engine.isRunning())
	{

		while(SDL_PollEvent(event))
		{
			engine.processEvent(event);
		}

		engine.updatePhysics();
		engine.renderFrame();

	}
	SDL_Log("Engine stopped running.");

	//std::thread gameLoop = std::thread(loop);

	//gameLoop.join();

	// // Initialize SDL with video
	// SDL_Init(SDL_INIT_VIDEO);
	
	// // Create an SDL window
	// SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	
	// // if failed to create a window
	// if(!window)
	// {
	// 	// we'll print an error message and exit
	// 	std::cerr << "Error failed to create window!\n";
	// 	return 1;
	// }
	
	// SDL_Surface *screenSurface = SDL_GetWindowSurface(window);

	// SDL_Event event;	 // used to store any events from the OS
	// bool running = true; // used to determine if we're running the game
	// SDL_Rect rect = {0, 0, 100, 100}; // x, y, width, height
    // SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x255));

    // SDL_UpdateWindowSurface(window);


	// Space* space = new Space();

	// space->addNode(new Square(), Coordinate(0, 0, 0));

	// while(running)
	// {
	// 	// poll for events from SDL
	// 	while(SDL_PollEvent(&event))
	// 	{
	// 		// determine if the user still wants to have the window open
	// 		// (this basically checks if the user has pressed 'X')
	// 		running = event.type != SDL_QUIT;

    //             switch (event.type)
    //             {
    //                 case SDL_KEYDOWN:
    //                         SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, rand() % 255, rand() % 255, rand() % 255));

    //                     break;
    //             }
    //         SDL_UpdateWindowSurface(window);

	// 	}


	/// 	// Swap OpenGL buffers


	// }
	
	
	// // Destroy the context
	// SDL_GL_DeleteContext(context);
	
	// // Destroy the window
	// SDL_DestroyWindow(window);
	
	// // And quit SDL
	// SDL_Quit();
	
	return 0;
}