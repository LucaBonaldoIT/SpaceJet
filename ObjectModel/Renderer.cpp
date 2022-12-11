#include "Renderer.hpp"

Renderer::SpriteList::SpriteList()
{
    for (const auto & entry : std::filesystem::directory_iterator(DEFAULT_SPRITES_PATH))
    {
        this->spriteIds.push_back(entry.path().filename().replace_extension());
    }
}


SDL_Texture* Renderer::loadTextureFromFile(SDL_Renderer *renderer, const char *file)
{
    SDL_Texture *texture = nullptr;
    SDL_Surface *surface = IMG_Load(file);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        Logger::log("Caricata!");
    }
    return texture;
}

void Renderer::loadSprites()
{
    for(const auto & sprite : spriteList.getSpriteIds())
    {
        this->sprites.insert({
            sprite,
            loadTextureFromFile(this->renderer,
                                spriteList.getSpritePath(sprite).c_str())
        });
    }
}

Renderer::Renderer()
{
    Renderer::rendererState = RendererState::RendererError;
}

Renderer::Renderer(SDL_Window* window)
{
    this->renderer = SDL_CreateRenderer(window,
                                        -1,
                                        SDL_RENDERER_ACCELERATED);
    rendererState = this->renderer == nullptr ? RendererState::RendererError : RendererState::RendererInitialized;
}

Renderer* Renderer::initialize()
{
    Renderer::rendererState = RendererState::RendererInitialized;

    this->loadSprites();

    return this;
}


Renderer* Renderer::getInstance(SDL_Window* window)
{
    if(Renderer::rendererState != RendererState::RendererUninitialized)
    {
        Logger::log("Error! Already initialized!");
        return nullptr;
    }

    Renderer::instance = (new Renderer(window))->initialize();

    return Renderer::instance;

}

Renderer* Renderer::getInstance()
{
    if(Renderer::rendererState == RendererState::RendererUninitialized)
    {
        Logger::log("Error! Uninitialized!");
    }

    return Renderer::instance;

}

RendererState Renderer::getState()
{
    return Renderer::rendererState;
}

void Renderer::clear()
{
    SDL_RenderClear(this->renderer);
}

void Renderer::draw(std::vector<Node*> nodes)
{
    for(const auto & node : nodes) 
    {
        SDL_RenderCopy(this->renderer,
                       this->sprites.at(node->getSpriteInfo().id),
                       nullptr,
                       nullptr);
    }
    
}

void Renderer::update()
{
    SDL_RenderPresent(this->renderer);
}