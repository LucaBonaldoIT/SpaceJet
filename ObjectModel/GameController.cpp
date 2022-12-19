#include "GameController.hpp"

GameController::GameController()
{

    _actionsByKeyCode = std::map<std::string, int>
    {
        {"DOWN", SDL_SCANCODE_DOWN},
        {"UP", SDL_SCANCODE_UP},
        {"LEFT", SDL_SCANCODE_LEFT},
        {"RIGHT", SDL_SCANCODE_RIGHT},
        
    };

}

void GameController::bind(std::string action, int keyCode)
{
    _actionsByKeyCode[action] = keyCode;
}

void GameController::processInput(KeyboardState state)
{

    Vector3d res = Vector3d();

    for ( const auto &[key, value] : _actionsByKeyCode ) {
        
        if (key == "DOWN")
        {
            if (state[value])
            {
                res = res + (Vector3d(0, 1, 0));
            }
            continue;
        }

        if (key == "UP")
        {
            if (state[value])
            {
                res = res + (Vector3d(0, -1, 0));
            }
            continue;
        }

        if (key == "LEFT")
        {
            if (state[value])
            {
                res = res + (Vector3d(-1, 0, 0));
            }
            continue;
        }

        if (key == "RIGHT")
        {
            if (state[value])
            {
                res = res + (Vector3d(1, 0, 0));
            }
            continue;
        }

    }

    Engine::getNodes().at(0)->setVelocity(res);

}


GameController* GameController::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new GameController();
    }

    return _instance;
}