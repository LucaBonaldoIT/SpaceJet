#ifndef NODE_H
#define NODE_H

struct SpriteInfo
{
    const char* id;
};

class Node
{
    public:
        virtual SpriteInfo getSpriteInfo() = 0;
        virtual void updateNodePhysics() = 0;

};

#endif