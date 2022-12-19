#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <SDL2/SDL.h>
#include <string>
#include <map>

#include "Vector3d.hpp"
#include "Engine.hpp"

typedef const Uint8* KeyboardState;

class GameController
{

    private:

    std::map<std::string,int> _actionsByKeyCode;
    
    static inline GameController* _instance = nullptr;

    GameController();

    public:

    static GameController* getInstance();

    void bind(std::string, int);

    void processInput(KeyboardState);

};

#endif