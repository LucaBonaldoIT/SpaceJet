#ifndef ENGINE_H
#define ENGINE_H

#include "Game.hpp"
#include "Renderer.hpp"
#include "Node.hpp"
#include "Logger.hpp"
#include "Square.hpp"
#include <vector>

enum EngineState {

    EngineError = -1,
    EngineUninitialized = 0,
    EngineInitialized = 1,
    EngineRunning = 2,
    EngineClosing = 3,

};

class Engine
{

    private:

    const char* WINDOW_TITLE = "Game";

    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;

    Engine* initialize();

    SDL_Window* window;

    Game game;
    Renderer* renderer;

    static inline std::vector<Node*> nodes;

    static inline EngineState state;

    Engine();

    static inline Engine* instance;

    public:

    ~Engine();

    static Engine* getInstance();

    void processEvent(SDL_Event*);

    void updatePhysics();
    void renderFrame();

    bool isRunning();

};

class WindowNotIstantiatedException : public std::exception 
{
    private:
        char * message;

    public:
        WindowNotIstantiatedException(char * msg) : message(msg){}
        char* what () {return message;}
};

class EngineNotIstantiatedException : public std::exception 
{
    private:
        char * message;

    public:
        EngineNotIstantiatedException(char * msg) : message(msg){}
        char* what () {return message;}
};

#endif