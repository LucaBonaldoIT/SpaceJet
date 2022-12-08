#ifndef ENGINE_H
#define ENGINE_H

#include "Game.hpp"
#include "Renderer.hpp"
#include "Node.hpp"
#include <vector>

class Engine
{

    private:

    const char* WINDOW_TITLE = "Game";

    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;

    static class Initializer
    {
        public:
        Initializer();
    } INITIALIZER;

    SDL_Window* window;

    Game game;
    Renderer* renderer;

    std::vector<Node*> nodes;

    enum GameState {

        Running = 0,
        Closing = 1,

    } state;

    public:


    Engine();
    ~Engine();

    void processEvent(SDL_Event*);

    void updatePhysics();
    void renderFrame();

    bool isRunning();

};

#endif