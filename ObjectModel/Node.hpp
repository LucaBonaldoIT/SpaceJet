#ifndef NODE_H
#define NODE_H

#include "Vector3d.hpp"

typedef float Mass;

struct SpriteInfo
{
    const char* id;

    SpriteInfo(const char* id) : id{id}
    {}

};

class Node
{
    private:
        Vector3d position;
        Vector3d velocity;
        Vector3d acceleration;
        Vector3d force;

        Mass mass;

    public:
        virtual SpriteInfo getSpriteInfo() = 0;
        virtual void updatePhysics() = 0;
        virtual void applyForce() = 0;
};

#endif