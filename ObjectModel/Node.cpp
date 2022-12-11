
#include "Node.hpp"

Node::Node()
{
    this-> mass = 1;
}

SpriteInfo Node::getSpriteInfo()
{
    return this->spriteInfo;
};
void Node::updatePhysics(DeltaTime dt)
{
    this->acceleration = this->acceleration + (this->force / this->mass);
    this->velocity = this->velocity + this->acceleration;
    this->position = this->position + this->velocity;
    this->force = Vector3d();
    return;
};
void Node::applyForce(Vector3d force)
{
    this->force = force;
};

Vector3d Node::getPosition()
{
    return this->position;
}
