#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <memory>

#include "Common.hpp"
#include "Renderer.hpp"
#include "Controller.hpp"
#include "Node.hpp"
#include "Player.hpp"
#include "Starfield.hpp"
#include "Field.hpp"
#include "Button.hpp"
#include "AudioPlayer.hpp"

enum GameState
{
    GameError = -1,
    GameMainMenu = 0,
    GameRunning = 1,
    GamePaused = 2

};

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

    //  ------------- States -------------
    static inline EngineState _state;
    static inline GameState _currentGameState;
    static inline GameState _previousGameState;


    AudioPlayer* audioPlayer;

    Engine* initialize();

    void initializeMenu();

    SDL_Window* window;

    Renderer* renderer;

    // ---------- Engine nodes ----------
    static inline std::vector<Node*> _nodes;
    static inline std::vector<Node*> _menuNodes;


    // Field instance pointer loaded into the engine
    std::unique_ptr<Field> field;

    Engine();

    static Engine* _instance;

    Controller* _controller;

    public:

    ~Engine();

    static Engine* getInstance();
    std::vector<Node*> getNodes();

    void updateGameState(GameState);
    
    void processEvent(SDL_Event*);

    void updatePhysics(DeltaTime dt);
    void renderFrame();

    void playSound(std::string sound) { this->audioPlayer->play(sound); }

    bool isRunning();

    GameState getCurrentGameState(){return _currentGameState;}
    GameState getPreviousGameState(){return _previousGameState;}

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