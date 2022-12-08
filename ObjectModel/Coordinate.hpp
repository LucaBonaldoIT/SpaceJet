#ifndef COORDINATE_H
#define COORDINATE_H

#include <cmath>

typedef float Point;

struct Coordinate
{
    Point x;
    Point y;
    Point z;

    public:

    inline Point module() const
    {
        return sqrt(this->energy());
    }

    inline Point energy() const
    {
        return x*x + y*y + z*z;
    }


    inline friend bool operator< (Coordinate const& c0, Coordinate const& c1)
    {
        return c0.energy() < c1.energy();
    }

    Coordinate(Point _x, Point _y, Point _z) : x{_x}, y{_y}, z{_z}
    {
    }

};

#endif