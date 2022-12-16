#ifndef NODE_H
#define NODE_H

#include "Vector3d.hpp"
#include "DeltaTime.hpp"

typedef float Mass;
typedef float Inertia;

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
        Vector3d _position;
        Vector3d _velocity;
        Vector3d _acceleration;
        Vector3d _force;

        Mass _mass;
        Inertia _inertia;

        // Holds sprite name
        SpriteInfo _spriteInfo;

        

    public:

        Node();

        SpriteInfo getSpriteInfo();
        void updatePhysics(DeltaTime);
        void applyForce(Vector3d);
        void applyImpulse(Vector3d);
        Vector3d getPosition();
};

#endif