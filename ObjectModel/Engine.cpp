#include "Engine.hpp"

Engine* Engine::_instance= nullptr;

Engine* Engine::initialize()
{

    if (_state != EngineState::EngineUninitialized)
    {
        return this;
    }

    Logger::log("Initializing SDL2...");

    auto err = SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO);

    if (err == 0)
    {
        Logger::log("SDL2 initialized...");
        return nullptr;
    }

    Logger::log("Initializing SDL2...");

    Engine::_state = EngineState::EngineInitialized;
    Engine::_previousGameState = GameState::GameError;
    Engine::_currentGameState = GameState::GameMainMenu;

    return this;

}



void Engine::updateGameState(GameState gameState)
{
    _previousGameState = _currentGameState;
    _currentGameState = gameState;
}

Engine* Engine::getInstance()
{
    if (_instance != nullptr)
    {
        return _instance;
    }

    _instance = (new Engine())->initialize();

    return _instance;
}


Engine::Engine()
{

    this->window = SDL_CreateWindow(Game::WindowTitle.c_str(),
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    Game::WindowWidth, Game::WindowHeight, 0);



    // Initialize game nodes
    Engine::_nodes = std::vector<Node*>({
        Player::getInstance()
    });
    // Initiliaze menu nodes
    this->initializeMenu();

    if (window == nullptr)
    {
        throw WindowNotIstantiatedException("Window not istantiated in Engine's constructor.");
        return;
    }


    // Load specific field instance
    field = std::unique_ptr<Field>(new Starfield());

    // Setup renderer and set running state
    this->renderer = Renderer::getInstance(this->window);
    Logger::log("Renderer istantiated.");
    Engine::_state = EngineState::EngineRunning;

    this->audioPlayer = AudioPlayer::getInstance();

}

void Engine::initializeMenu()
{
    _menuNodes = std::vector<Node*>({
        new Button("resumeButton", math::Vector2d(Game::WindowWidth / 2 - 75, Game::WindowHeight / 2 - 50), math::Vector2d(150, 100))
    });
}

Engine::~Engine()
{
    SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void Engine::processEvent(SDL_Event* event)
{
    Engine::_state = event->type == SDL_QUIT ? EngineState::EngineClosing : EngineState::EngineRunning;

    _controller->getInstance()->processInput(SDL_GetKeyboardState(nullptr));

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
    
    field->updateField(dt);

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
    this->renderer->getInstance()->draw(field->getFieldNodes());
    this->renderer->getInstance()->draw(_nodes);

    if (_currentGameState == GameState::GamePaused)
    {
        this->renderer->getInstance()->draw(_menuNodes);
    }
    this->renderer->getInstance()->update();

}

bool Engine::isRunning()
{
    return Engine::_state == EngineState::EngineRunning;
}

