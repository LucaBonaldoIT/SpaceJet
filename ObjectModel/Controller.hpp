#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <string>
#include <map>
#include "Vector3d.hpp"
#include "Player.hpp"
#include "Logger.hpp"
#include "Types.hpp"

class Controller
{

    private:

    std::map<std::string,int> _actionsByKeyCode;
    
    static inline Controller* _instance = nullptr;

    Controller();

    public:

    static Controller* getInstance();

    void bind(std::string, int);

    void processInput(KeyboardState);

};

#endif