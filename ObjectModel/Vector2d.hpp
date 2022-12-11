#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <cmath>

typedef float Point;

struct Vector2d
{
    Point x;
    Point y;

    inline Point module() const
    {
        return sqrt(this->energy());
    }

    inline Point energy() const
    {
        return x*x + y*y;
    }

    Vector2d(Point _x, Point _y) : x{_x}, y{_y}
    {
    }

};

#endif