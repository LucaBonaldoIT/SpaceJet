#ifndef BOX_H
#define BOX_H

class Box
{
    virtual bool isCollidingWith(Box&);
    virtual bool isOutOfBounds();
};

#endif