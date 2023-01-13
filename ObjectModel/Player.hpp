#ifndef PLAYER_H
#define PLAYER_H

#include "Common.hpp"
#include "Node.hpp"

class Player : public Node
{
    private:

    Speed _defaultSpeed = 1000;
    Speed _maxSpeed = 1000;

    static Player* _instance;
    Player()
    {
        _spriteInfo = SpriteInfo("player");
        _widthRatio = 3.0f;
        _heightRatio = 3.0f;
        _width = _widthRatio * 125;
        _height = _heightRatio * 115;
    }
    public:

    static Player* getInstance();

    Speed getDefaultSpeed()
    {
        return _defaultSpeed;
    }

    Speed getMaxSpeed()
    {
        return _maxSpeed;
    }
};

#endif