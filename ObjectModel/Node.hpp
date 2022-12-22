#ifndef NODE_H
#define NODE_H

#include "Vector3d.hpp"
#include "DeltaTime.hpp"
#include "Types.hpp"

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
        float _widthRatio;
        float _heightRatio;

        

    public:

        Node();

        

        // ------------- Sprites info -------------
        SpriteInfo getSpriteInfo();
        Ratio getWidthRatio(){return _widthRatio;};
        Ratio getHeightRatio(){return _heightRatio;};

        void setRatio(Ratio);

        // ------------- Physics actions -------------

        virtual Speed getMaxSpeed() = 0;
        virtual Speed getDefaultSpeed() = 0;

        Vector3d getPosition();
        void setPosition(Vector3d);

        void updatePhysics(DeltaTime);
        void applyForce(Vector3d);
        void applyImpulse(Vector3d);
        void applyVelocity(Vector3d);
        void setVelocity(Vector3d);
};

#endif