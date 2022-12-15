#ifndef SQUARE_H
#define SQUARE_H

#include "Node.hpp"

class Square : public Node
{
    public:
        Square()
        {
            _spriteInfo = SpriteInfo("minion");
        }
};

#endif