#ifndef SQUARE_H
#define SQUARE_H

#include "Node.hpp"

class Square : public Node
{


    public:
        Square()
        {
            _spriteInfo = SpriteInfo("minion");
            width_ratio = 0.333f;
            height_ratio = 0.333f;
        }

        Speed getMaxSpeed()
        {
            return 2;
        }

};

#endif