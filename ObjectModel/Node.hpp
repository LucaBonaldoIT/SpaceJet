#ifndef NODE_H
#define NODE_H

#include <SDL2/SDL.h>

#include "Vector3d.hpp"
#include "DeltaTime.hpp"
#include "Types.hpp"
#include "Game.hpp"

struct SpriteInfo
{
    const char* id;
    size_t _width;
    size_t _height;

    SpriteInfo(const char* id) : id{id}
    {}

    SpriteInfo(const char* id, size_t width, size_t height) : id{id}, _height{height}, _width{width}
    {}


    SpriteInfo() : id{"default"}
    {
    }

};

class Node
{
    protected:
        math::Vector3d _position;
        math::Vector3d _velocity;
        math::Vector3d _acceleration;
        math::Vector3d _force;

        Mass _mass;
        Inertia _inertia;

        // Holds sprite name
        SpriteInfo _spriteInfo;
        // Sprite size ratio of this instance sprite to original image
        float _widthRatio;
        float _heightRatio;
        size_t _width = 1;
        size_t _height = 1;        

    public:

        Node();

        

        // ------------- Sprites info -------------
        SpriteInfo getSpriteInfo();
        // Ratio getWidthRatio(){return _widthRatio;}
        // Ratio getHeightRatio(){return _heightRatio;}
        size_t getWidth(){return _width;}
        size_t getHeight(){return _height;}

        void setRatio(Ratio);

        // ------------- Physics actions -------------

        virtual Speed getMaxSpeed() = 0;
        virtual Speed getDefaultSpeed() = 0;

        math::Vector3d getPosition();
        void setPosition(math::Vector3d);

        void updatePhysics(DeltaTime);
        void applyForce(math::Vector3d);
        void applyImpulse(math::Vector3d);
        void applyVelocity(math::Vector3d);
        void setVelocity(math::Vector3d);

        // 
        bool isOutOfBounds();
};

#endif