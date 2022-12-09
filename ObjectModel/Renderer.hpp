#ifndef RENDERER_H
#define RENDERER_H

#include "Logger.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include <vector>
#include <filesystem>

enum RendererState
{
    RendererError = -1,
    RendererUninitialized = 0,
    RendererInitialized = 1
};

class Renderer
{

    private:

    class SpriteList
    {
        std::vector<std::string> spriteIds;
        
        public:
        const std::string DEFAULT_SPRITES_PATH = "./sprites/";
        SpriteList();
        std::vector<std::string> getSpriteIds() {return this->spriteIds;};
        std::string getSpritePath(std::string sprite) {return this->DEFAULT_SPRITES_PATH + sprite;}

    } spriteList;


    static inline RendererState rendererState;
    
    SDL_Renderer* renderer;

    std::map <std::string, SDL_Texture*> sprites;

    void loadSprites();

    SDL_Texture* loadTextureFromFile(SDL_Renderer *renderer, const char *file);

    Renderer* initialize();

    Renderer(SDL_Window*);

    static inline Renderer* instance;

    public:

    Renderer();

    static Renderer* getInstance(SDL_Window*);
    static Renderer* getInstance();

    RendererState getState();

};

#endif