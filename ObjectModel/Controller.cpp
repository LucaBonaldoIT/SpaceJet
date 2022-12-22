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
        
    };

}

void Controller::bind(std::string action, int keyCode)
{
    _actionsByKeyCode[action] = keyCode;
}

void Controller::processInput(KeyboardState state)
{

    Vector3d res = Vector3d();

    for ( const auto &[key, value] : _actionsByKeyCode ) {
   
    
        if (key == "DOWN")
        {
            if (state[value])
            {
                res = res + DOWN_VECTOR_3D;

            }
            continue;
        }

        if (key == "UP")
        {
            if (state[value])
            {
                res = res + UP_VECTOR_3D;

            }
            continue;
        }

        if (key == "LEFT")
        {
            if (state[value])
            {
                res = res + LEFT_VECTOR_3D;

            }
            continue;
        }

        if (key == "RIGHT")
        {
            if (state[value])
            {
                res = res + RIGHT_VECTOR_3D;

            }
            continue;
        }
    }

    res = res / (res.module() > 0 ? res.module() : 1);
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