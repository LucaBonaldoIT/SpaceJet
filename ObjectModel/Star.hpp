#ifndef STAR_H
#define STAR_H

#include "Game.hpp"
#include "Node.hpp"

class Star : public Node
{

    private:

    public: 
    
    Star()
    {
        _spriteInfo = SpriteInfo("star");
        _widthRatio = 1.0f;
        _heightRatio = 1.0f;
        _position.x = rand() % 1500;
        _position.y = rand() % 1500;
        _position.z = 1280;

    }
        Speed getMaxSpeed()
        {
            return 0;
        }
Speed getDefaultSpeed()
        {
            return 0;
        }
};

#endif