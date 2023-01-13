#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "Node.hpp"

/**
 * Interface for field objects. It is possible to interact with
 * the engine class through updateField and getFieldNodes.
*/
class Field
{
    public:
        virtual void updateField(DeltaTime dt) = 0;
        virtual std::vector<Node*> getFieldNodes() = 0;

};

#endif