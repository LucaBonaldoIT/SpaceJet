#ifndef BUTTON_H
#define BUTTON_H


#include "Common.hpp"
#include "Node.hpp"

class Button : public Node
{
    private:

    public:

    Button(const char* spriteName, math::Vector2d position, math::Vector2d size)
    {
        _spriteInfo = SpriteInfo(spriteName);
        _widthRatio = 1.0f;
        _heightRatio = 1.0f;
        _width = _widthRatio * size.x;
        _height = _heightRatio * size.y;

        _position = math::Vector3d(position.x, position.y, 0);
    }

    Speed getDefaultSpeed()
    {
        return 0;
    }

    Speed getMaxSpeed()
    {
        return 0;
    }
};

#endif