#include "Space.hpp"

void Space::addNode(Node* node, Coordinate const coordinate)
{
    if(this->space.count(coordinate) == 0)
    {
        this->space[coordinate] = node;
    }
}