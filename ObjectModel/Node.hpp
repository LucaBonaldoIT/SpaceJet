#ifndef NODE_H
#define NODE_H

struct SpriteInfo
{
    const char* id;
};

class Node
{

    virtual SpriteInfo getSpriteInfo();

};

#endif