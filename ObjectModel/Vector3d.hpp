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

    Vector3d() : x{0.0f}, y{0.0f}, z{0.0f}
    {
    }

    Vector3d(Point _x, Point _y, Point _z) : x{_x}, y{_y}, z{_z}
    {
    }

    Vector3d operator+(const Vector3d& other)
    {
        return Vector3d(x + other.x, y + other.y, z + other.z);
    }

    Vector3d operator-(const Vector3d& other)
    {
        return Vector3d(x - other.x, y - other.y, z - other.z);
    }

    Vector3d operator*(const Point& other)
    {
        return Vector3d(x * other, y * other, z * other);
    }

    Vector3d operator/(const Point& other)
    {
        return Vector3d(x / other, y / other, z / other);
    }

};

const Vector3d UP_VECTOR_3D     = Vector3d( 0,-1, 0);
const Vector3d DOWN_VECTOR_3D   = Vector3d( 0, 1, 0);
const Vector3d RIGHT_VECTOR_3D  = Vector3d( 1, 0, 0);
const Vector3d LEFT_VECTOR_3D   = Vector3d(-1, 0, 0);

#endif