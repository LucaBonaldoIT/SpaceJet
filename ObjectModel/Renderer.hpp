#ifndef RENDERER_H
#define RENDERER_H

#include <map>
#include <string>
#include <vector>
#include <filesystem>

#include "Common.hpp"
#include "Node.hpp"

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

        /**
         * Initializes an internal list with sprite names (spriteIds)
         * from ./sprites/ folder. Only names are kept, extensions are
         * removed.
        */
        SpriteList();
        
        std::vector<std::string> getSpriteIds() {return this->spriteIds;};
        std::string getSpritePath(std::string sprite) {return DEFAULT_SPRITES_PATH + sprite + DEFAULT_FILE_EXT;}

    } spriteList;


    static inline RendererState rendererState;
    
    SDL_Renderer* renderer;

    std::map <std::string, SDL_Texture*> sprites;

    /**
     * @brief Loads all sprites from spriteList in sprites map,
     * binding each string (key) with a SDL_Texture* (value).
     */
    void loadSprites();

    /**
     * @brief Load single texture from file through SDL's functions.
     * 
     * @param renderer 
     * @param file 
     * @return SDL_Texture* to be added as value in sprites map.
     */
    SDL_Texture* loadTextureFromFile(SDL_Renderer *renderer, const char *file);

    /**
     * @brief Sets renderer's state to initialized and loads sprites in memory.
     * 
     * @return Renderer* this instance
     */
    Renderer* initialize();

    Renderer(SDL_Window*);

    static Renderer* _instance;

    math::Vector2d projectVector(math::Vector3d);   //???

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