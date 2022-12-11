#ifndef RENDERER_H
#define RENDERER_H

#include "Logger.hpp"
#include "Node.hpp"
#include "Vector3d.hpp"
#include "Vector2d.hpp"

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
        const std::string DEFAULT_FILE_EXT = ".png";
        SpriteList();
        std::vector<std::string> getSpriteIds() {return this->spriteIds;};
        std::string getSpritePath(std::string sprite) {return DEFAULT_SPRITES_PATH + sprite + DEFAULT_FILE_EXT;}

    } spriteList;


    static inline RendererState rendererState;
    
    SDL_Renderer* renderer;

    std::map <std::string, SDL_Texture*> sprites;

    void loadSprites();

    SDL_Texture* loadTextureFromFile(SDL_Renderer *renderer, const char *file);

    Renderer* initialize();

    Renderer(SDL_Window*);

    static inline Renderer* instance;

    Vector2d projectVector(Vector3d);

    public:

    Renderer();

    static Renderer* getInstance(SDL_Window*);
    static Renderer* getInstance();

    void clear();
    void draw(std::vector<Node*>);
    void update();

    RendererState getState();

};

#endif