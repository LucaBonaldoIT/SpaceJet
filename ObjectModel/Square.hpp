#ifndef SQUARE_H
#define SQUARE_H

#include "Node.hpp"

class Square : public Node
{
    public:
        Square()
        {
            this->spriteInfo = SpriteInfo("minion");
        }
};

#endif