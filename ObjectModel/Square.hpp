#ifndef SQUARE_H
#define SQUARE_H

#include "Node.hpp"

class Square : public Node
{
        SpriteInfo getSpriteInfo()
        {
            return SpriteInfo("Square!");
        };
        void updateNodePhysics()
        {
            return;
        };
};

#endif