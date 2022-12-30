
#include "Node.hpp"

Node::Node()
{
    _mass = 1;
    _inertia = 0.99;
}

SpriteInfo Node::getSpriteInfo()
{
    return _spriteInfo;
};
void Node::updatePhysics(DeltaTime dt)
{
    // _acceleration = _acceleration * _inertia + (_force * (1/_inertia) / _mass);
    // _velocity = _velocity + _acceleration * 4;
    // _position = _position + _velocity;
    // _force = Vector3d();

    // ???
    _velocity = _velocity + ((_force / _mass) * dt);
    _position = _position + ((_velocity) * dt);
    _force = Vector3d();

    return;
};
void Node::applyForce(Vector3d force)
{
    _force = force;
};

void Node::applyVelocity(Vector3d velocity)
{
    _velocity = _velocity + velocity;
};

void Node::applyImpulse(Vector3d impulse)
{
    // m(v2-v1)=J - Impulse theorem
    _velocity = _velocity + impulse / _mass;
}

void Node::setVelocity(Vector3d velocity)
{
    _velocity = velocity * 1;
}

void Node::setRatio(Ratio ratio)
{
    _widthRatio = ratio;
    _heightRatio = ratio;
}

Vector3d Node::getPosition()
{
    return _position;
}

void Node::setPosition(Vector3d position)
{
    _position = position;
}

bool Node::isOutOfBounds()
{return _position.x > Game::WindowWidth || 
        _position.y > Game::WindowHeight || 
        _position.x < 0 ||
        _position.y < 0;
}