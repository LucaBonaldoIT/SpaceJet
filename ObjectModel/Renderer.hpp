#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include <vector>
#include <filesystem>

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

    SDL_Renderer* renderer;

    std::map <std::string, SDL_Texture*> sprites;

    void loadSprites();

    SDL_Texture* loadTextureFromFile(SDL_Renderer *renderer, const char *file);

    public:

    Renderer();
    Renderer(SDL_Window*);

};

#endif