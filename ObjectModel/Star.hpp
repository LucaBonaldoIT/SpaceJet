#ifndef STAR_H
#define STAR_H

#include "Game.hpp"
#include "Random.hpp"
#include "Node.hpp"

class Star : public Node
{

    private:

    const int SpawnWidthMin = 0;
    const int SpawnWidthMax = Game::WindowWidth;

    const int SpawnHeightMin = 0;
    const int SpawnHeightMax = Game::WindowHeight;

    const int SpawnZMin = 0;
    const int SpawnZtMax = Game::WindowHeight;

    public: 
    
    Star()
    {
        _spriteInfo = SpriteInfo("star");
        
        _widthRatio = 1.0f;
        _heightRatio = 1.0f;

        _position.x = Random::getSingleInt(SpawnWidthMin, SpawnWidthMax);
        _position.y = Random::getSingleInt(SpawnHeightMin, SpawnHeightMax);
        _position.z = Random::getSingleInt(SpawnZMin, SpawnZtMax);

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