#include "Starfield.hpp"

const Tensor Starfield::RotationMatrix = Tensor::getRotationMatrix3d(_rotationSpeed);

void Starfield::generateStars() 
{
    for(int i = 0; i < STAR_NUM; i++)
    {
        _stars.push_back(new Star());
    }
}

void Starfield::updateStars()
{
    _rotationPivot = Player::getInstance()->getPosition();
    //Logger::log(_rotationPivot);

    for (int i = 0; i < STAR_NUM; i++)
    {
        Node* star = _stars[i];
        Vector3d starInitialPosition = star->getPosition();
        

        // Traslate star
        Vector3d starMovement = starInitialPosition - _rotationPivot;   // Distance vector from the rotation point
        starMovement = starMovement / starMovement.module();            
        auto pos = starInitialPosition + ((starMovement * _expansionSpeed) / starInitialPosition.z);

        // Star rotation
        pos = rotateAround(pos, _rotationPivot);
        pos.z = std::max(1.0f, starInitialPosition.z - 0.001f);


        if (star->isOutOfBounds())
        {
            // Replace the node inside the bounds

            // Move star "just a bit outside" the screen
            pos.x = Random::getSingleInt(-BorderSpawnWidth, Game::WindowWidth + BorderSpawnWidth);
            pos.y = Random::getSingleInt(-BorderSpawnHeight, Game::WindowHeight + BorderSpawnHeight);
            pos.z = 3;   

            // Logger::log("Star teleported from");
            // Logger::log((std::string)starInitialPosition);
            // Logger::log("to");
            // Logger::log((std::string)pos);
        }
            
        // Update star
        star->setPosition(pos);
        star->setRatio(std::min(3000.0/pos.z, 2.0));

    }
}

Vector3d Starfield::rotateAround(Vector3d position, Vector3d pivot)
{
    position = position - pivot;
    position.z = 1;
    Tensor newPositionTensor = RotationMatrix * position;
    Vector3d newPosition = (Vector3d)newPositionTensor;
    newPosition = newPosition + pivot;
    return newPosition;
}

std::vector <Node*> Starfield::getStars()
{
    return _stars;
}
