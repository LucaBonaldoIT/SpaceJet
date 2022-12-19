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
                res = res + (Vector3d(0, 1, 0));
                        Logger::log((key + "\n").c_str());

            }
            continue;
        }

        if (key == "UP")
        {
            if (state[value])
            {
                res = res + (Vector3d(0, -1, 0));
                        Logger::log((key + "\n").c_str());

            }
            continue;
        }

        if (key == "LEFT")
        {
            if (state[value])
            {
                res = res + (Vector3d(-1, 0, 0));        Logger::log((key + "\n").c_str());

            }
            continue;
        }

        if (key == "RIGHT")
        {
            if (state[value])
            {
                res = res + (Vector3d(1, 0, 0));        Logger::log((key + "\n").c_str());

            }
            continue;
        }
    }

    try{
        Engine::getInstance()->getNodes().at(0)->setVelocity(res);
                Logger::log("CIao");
    }       
    catch (const std::exception& e){
        ;}
}


Controller* Controller::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new Controller();
    }

    return _instance;
}