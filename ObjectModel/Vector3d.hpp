#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <cmath>

typedef float Point;

struct Vector3d
{
    Point x;
    Point y;
    Point z;

    inline Point module() const
    {
        return sqrt(this->energy());
    }

    inline Point energy() const
    {
        return x*x + y*y + z*z;
    }

    Vector3d() : x{Point()}, y{Point()}, z{Point()}
    {
    }

    Vector3d(Point _x, Point _y, Point _z) : x{_x}, y{_y}, z{_z}
    {
    }

};

#endif