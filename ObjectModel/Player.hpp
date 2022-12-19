#include "Node.hpp"

#ifndef PLAYER_H
#define PLAYER_H

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

    Speed getMaxSpeed()
    {
        return 2;
    }
};

#endif