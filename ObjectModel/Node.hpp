#ifndef NODE_H
#define NODE_H

#include "Vector3d.hpp"
#include "DeltaTime.hpp"

typedef float Mass;

struct SpriteInfo
{
    const char* id;

    SpriteInfo(const char* id) : id{id}
    {}

    SpriteInfo() : id{"default"}
    {
    }

};

class Node
{
    protected:
        Vector3d position;
        Vector3d velocity;
        Vector3d acceleration;
        Vector3d force;

        Mass mass;

        SpriteInfo spriteInfo;

    public:

        Node();

        SpriteInfo getSpriteInfo();
        void updatePhysics(DeltaTime);
        void applyForce(Vector3d);
        Vector3d getPosition();
};

#endif