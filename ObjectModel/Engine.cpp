#include "Engine.hpp"

Engine::Initializer::Initializer()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

Engine::Engine()
{

    this->window = SDL_CreateWindow(WINDOW_TITLE,
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    WINDOW_WIDTH, WINDOW_HEIGHT, 0);


    if (window == nullptr)
    {
        // To-do: create custom exception
        ;
    }

    this->renderer = new Renderer(this->window);

    this->state = GameState::Running;

}

Engine::~Engine()
{
    SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void Engine::processEvent(SDL_Event* event)
{
    this->state = event->type == SDL_QUIT ? GameState::Closing : GameState::Running;
}

void Engine::updatePhysics()
{
}

void Engine::renderFrame()
{
}

bool Engine::isRunning()
{
    return this->state == GameState::Running;
}