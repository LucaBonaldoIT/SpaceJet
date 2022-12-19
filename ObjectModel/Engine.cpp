#include "Engine.hpp"

#include <iostream>

Engine* Engine::initialize()
{

    Logger::log("Initializing SDL2...");

    auto err = SDL_Init(SDL_INIT_EVERYTHING);

    if (err == 0)
    {
        Logger::log("SDL2 initialized...");
        return nullptr;
    }

    Logger::log("Initializing SDL2...");

    Engine::state = EngineState::EngineInitialized;

    return this;

}

Engine* Engine::getInstance()
{
    if (Engine::state == EngineState::EngineInitialized)
    {
        return Engine::_instance;
    }

    Engine::_instance = (new Engine())->initialize();

    return Engine::_instance;
}


Engine::Engine()
{

    this->window = SDL_CreateWindow(WINDOW_TITLE,
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    WINDOW_WIDTH, WINDOW_HEIGHT, 0);


    Engine::_nodes = std::vector<Node*>({
        new Square()
    });

    if (window == nullptr)
    {
        throw WindowNotIstantiatedException("Window not istantiated in Engine's constructor.");
        return;
    }


    // Setup renderer and set running state
    this->renderer = Renderer::getInstance(this->window);
    Logger::log("Renderer istantiated.");
    Engine::state = EngineState::EngineRunning;

}

Engine::~Engine()
{
    SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void Engine::processEvent(SDL_Event* event)
{
    Engine::state = event->type == SDL_QUIT ? EngineState::EngineClosing : EngineState::EngineRunning;

    // if (event->type == SDL_KEYDOWN)
    // {

        
        _controller->getInstance()->processInput(SDL_GetKeyboardState(nullptr));



    // }


    // if (event->type == SDL_KEYUP)
    // {
    //     switch (event->key.keysym.sym)
    //     {
    //     case SDLK_d:
    //         //this->nodes.at(0)->applyForce(Vector3d(0.00001, 0, 0));
    //         this->nodes.at(0)->setVelocity(Vector3d(0., 0, 0));
    //         break;
    //     case SDLK_w:
    //         this->nodes.at(0)->setVelocity(Vector3d(0, 0., 0));
    //         break;
    //     case SDLK_a:
    //         this->nodes.at(0)->setVelocity(Vector3d(0., 0, 0));
    //         break;
    //     case SDLK_s:
    //         this->nodes.at(0)->setVelocity(Vector3d(0, 0., 0));
    //         break;
    //     default:
    //         break;
    //     }
    // }

}

std::vector<Node*> Engine::getNodes()
{
    if(_instance == nullptr)
    {
        return std::vector<Node*>();
    }

    return _nodes;

}


void Engine::updatePhysics(DeltaTime dt)
{
    for (auto it = Engine::_nodes.begin(); it != Engine::_nodes.end(); it++)
    {
        // Update each node physics
        Node* current = *it;
        current->updatePhysics(dt);
    }
}

void Engine::renderFrame()
{

    this->renderer->getInstance()->clear();
    this->renderer->getInstance()->draw(this->_nodes);
    this->renderer->getInstance()->update();

}

bool Engine::isRunning()
{
    return Engine::state == EngineState::EngineRunning;
}

