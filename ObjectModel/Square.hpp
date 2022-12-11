#ifndef SQUARE_H
#define SQUARE_H

#include "Node.hpp"

class Square : public Node
{
        SpriteInfo getSpriteInfo()
        {
            return SpriteInfo("minion");
        };
        void updateNodePhysics()
        {
            return;
        };
};

#endif