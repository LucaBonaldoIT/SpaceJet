#include "Controller.hpp"
#include "Engine.hpp"

Controller::Controller()
{

    _actionsByKeyCode = std::map<std::string, int>
    {
        {"DOWN", SDL_SCANCODE_DOWN},
        {"UP", SDL_SCANCODE_UP},
        {"LEFT", SDL_SCANCODE_LEFT},
        {"RIGHT", SDL_SCANCODE_RIGHT},
        {"ESC", SDL_SCANCODE_ESCAPE}
        
    };

}

void Controller::bind(std::string action, int keyCode)
{
    _actionsByKeyCode[action] = keyCode;
}

void Controller::processInput(KeyboardState state)
{

    math::Vector3d res = math::Vector3d();

    for ( const auto &[key, value] : _actionsByKeyCode ) {
   
    
        if (key == "DOWN")
        {
            if (state[value])
            {
                res = res + math::DOWN_VECTOR_3D;

            }
            continue;
        }

        if (key == "UP")
        {
            if (state[value])
            {
                res = res + math::UP_VECTOR_3D;

            }
            continue;
        }

        if (key == "LEFT")
        {
            if (state[value])
            {
                res = res + math::LEFT_VECTOR_3D;

            }
            continue;
        }

        if (key == "RIGHT")
        {
            if (state[value])
            {
                res = res + math::RIGHT_VECTOR_3D;

            }
            continue;
        }

        if (key == "ESC")
        {
            if (state[value])
            {
                auto instance = Engine::getInstance();
                instance->updateGameState(instance->getCurrentGameState() == GameState::GameRunning ? GameState::GamePaused : GameState::GameRunning);
                instance->playSound("click");
            }
            continue;
        }
    }

    // Normalize avoiding zero division
    res = res / (res.module() > 0 ? res.module() : 1);
    // Multiplying normalized vector for player speed
    res = res * Player::getInstance()->getDefaultSpeed();

    Player::getInstance()->setVelocity(res);
}


Controller* Controller::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new Controller();
    }

    return _instance;
}