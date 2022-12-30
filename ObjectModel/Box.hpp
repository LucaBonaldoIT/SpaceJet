#ifndef BOX_H
#define BOX_H

#include "Common.hpp"

class Box
{
    private:
        Vector3d& _position;    // Starting point of cube collider
        Vector3d _dimensions;   // Ending ...

    public:
        Box(Vector3d& position, Vector3d dimensions);

    virtual bool isCollidingWith(Box&);
};

#endif