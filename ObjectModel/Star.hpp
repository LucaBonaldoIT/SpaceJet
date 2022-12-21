#ifndef STAR_H
#define STAR_H

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
        // _position.x = rand() % 1280;
        // _position.y = rand() % 720;
        _position.x = rand() % 1500;
        _position.y = rand() % 1500;    // Rotation testing
        _position.z = 1280;

    }
        Speed getMaxSpeed()
        {
            return 0;
        }

};

#endif