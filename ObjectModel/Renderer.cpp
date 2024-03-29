#include "Renderer.hpp"

Renderer* Renderer::_instance= nullptr;

Renderer::SpriteList::SpriteList()
{
    for (const auto & entry : std::filesystem::directory_iterator(DEFAULT_SPRITES_PATH))
    {
        this->spriteIds.push_back(entry.path().filename().replace_extension()); // replace_extension removes extension
    }
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
    for(const auto & sprite : spriteList.getSpriteIds())
    {
        // Insert sprite in sprites map (id, SDL_Texture*)
        this->sprites.insert({
            sprite,
            loadTextureFromFile(this->renderer,
                                spriteList.getSpritePath(sprite).c_str())
        });

        Logger::log("Loaded sprite: " + sprite);
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

    Renderer::_instance = (new Renderer(window))->initialize();

    return Renderer::_instance;

}

Renderer* Renderer::getInstance()
{
    if(Renderer::rendererState == RendererState::RendererUninitialized)
    {
        Logger::log("Error! Uninitialized!");
    }

    return Renderer::_instance;

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
        SDL_Rect rect;

        rect.x = node->getPosition().x;
        rect.y = node->getPosition().y;

        rect.w = node->getWidth();
        rect.h = node->getHeight();

        // Align texture center to position
        rect.x -= (rect.w / 2);
        rect.y -= (rect.h / 2);

        SDL_RenderCopy(this->renderer,
                       this->sprites.at(node->getSpriteInfo().id),
                       nullptr,
                       &rect);
    }
    
}

void Renderer::update()
{
    SDL_RenderPresent(this->renderer);
}