#ifndef SPACE_H
#define SPACE_H

#include "Node.hpp"
#include "Coordinate.hpp"
#include <map>

class Space
{
    private:

    std::map<Coordinate, Node*> space;

    public:

    void addNode(Node*, Coordinate const);

};

#endif