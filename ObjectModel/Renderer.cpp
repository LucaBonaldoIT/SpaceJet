#include "Renderer.hpp"

Renderer::SpriteList::SpriteList()
{
    for (const auto & entry : std::filesystem::directory_iterator(DEFAULT_SPRITES_PATH))
        this->spriteIds.push_back(entry.path());
}


SDL_Texture* Renderer::loadTextureFromFile(SDL_Renderer *renderer, const char *file)
{
    SDL_Texture *texture = nullptr;
    SDL_Surface *surface = IMG_Load(file);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    return texture;
}

void Renderer::loadSprites()
{
    for(auto sprite : spriteList.getSpriteIds())
    {
        this->sprites.insert({sprite, loadTextureFromFile(this->renderer, spriteList.getSpritePath(sprite).c_str())});
    }
}

Renderer::Renderer()
{}

Renderer::Renderer(SDL_Window* window)
{
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
