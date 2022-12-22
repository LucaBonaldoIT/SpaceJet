#ifndef PLAYER_H
#define PLAYER_H

#include "Common.hpp"
#include "Node.hpp"

class Player : public Node
{
    private:

    static Player* _instance;
    Player()
    {
        _spriteInfo = SpriteInfo("player");
        _widthRatio = 3.0f;
        _heightRatio = 3.0f;
    }
    public:

    static Player* getInstance();

    Speed getDefaultSpeed()
    {
        return 1000;
    }

    Speed getMaxSpeed()
    {
        return 1000;
    }
};

#endif