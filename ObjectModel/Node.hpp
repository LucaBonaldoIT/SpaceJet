#ifndef NODE_H
#define NODE_H

#include "Vector3d.hpp"
#include "DeltaTime.hpp"

typedef double Speed;
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
        // Sprite size ratio of this instance sprite to original image
        float width_ratio;
        float height_ratio;

        

    public:

        Node();

        

        // ------------- Sprites info -------------
        SpriteInfo getSpriteInfo();
        float getWidthRatio(){return width_ratio;};
        float getHeightRatio(){return height_ratio;};

        // ------------- Physics actions -------------

        virtual Speed getMaxSpeed() = 0;

        void updatePhysics(DeltaTime);
        void applyForce(Vector3d);
        void applyImpulse(Vector3d);
        void applyVelocity(Vector3d);
        void setVelocity(Vector3d);
        Vector3d getPosition();
};

#endif