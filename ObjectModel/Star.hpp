#ifndef STAR_H
#define STAR_H

#include "Common.hpp"
#include "Node.hpp"

class Star : public Node
{

    private:

    const int SpawnWidthMin = 0;
    const int SpawnWidthMax = Game::WindowWidth;

    const int SpawnHeightMin = 0;
    const int SpawnHeightMax = Game::WindowHeight;

    const int SpawnZMin = 2;
    const int SpawnZMax = 3;

    public: 
    
    Star()
    {
        _spriteInfo = SpriteInfo("star");
        
        _widthRatio = 1.0f;
        _heightRatio = 1.0f;
        _width = 8;
        _height = 8;

        _position.x = Random::getSingleInt(SpawnWidthMin, SpawnWidthMax);
        _position.y = Random::getSingleInt(SpawnHeightMin, SpawnHeightMax);
        _position.z = Random::getSingleInt(SpawnZMin, SpawnZMax);

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