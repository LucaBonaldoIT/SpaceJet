#include "Starfield.hpp"

const Tensor Starfield::RotationMatrix = Tensor::getRotationMatrix3d(_rotationSpeed);

void Starfield::generateStars() 
{
    for(int i = 0; i < STAR_NUM; i++)
    {
        _stars.push_back(new Star());
    }
}

void Starfield::updateStars(DeltaTime dt)
{
    _rotationPivot = Player::getInstance()->getPosition();
    //Logger::log(_rotationPivot);

    for (int i = 0; i < STAR_NUM; i++)
    {
        Node* star = _stars[i];
        Vector3d starInitialPosition = star->getPosition();
        Vector3d starFinalPosition;

        // Star expansion
        Vector3d starExpansion = starInitialPosition - _rotationPivot;   // Distance vector from the rotation point
        starExpansion = starExpansion.normalized();            
        starFinalPosition = starInitialPosition + ((starExpansion * _expansionSpeed) / starInitialPosition.z) * dt;

        // Star rotation
        starFinalPosition = rotateAround(starFinalPosition, _rotationPivot, dt);
        starFinalPosition.z = std::max(1.0f, starInitialPosition.z - 0.001f);


        if (star->isOutOfBounds())
        {
            // Move star "just a bit outside" the screen
            starFinalPosition.x = Random::getSingleInt(-BorderSpawnWidth, Game::WindowWidth + BorderSpawnWidth);
            starFinalPosition.y = Random::getSingleInt(-BorderSpawnHeight, Game::WindowHeight + BorderSpawnHeight);
            starFinalPosition.z = 3;   
        }
            
        // Update star
        star->setPosition(starFinalPosition);
        star->setRatio(std::min(3000.0/starFinalPosition.z, 2.0));

    }
}

Vector3d Starfield::rotateAround(Vector3d position, Vector3d pivot, DeltaTime dt)
{
    // Old rotation code with matrix multiplication
    // position = position - pivot;
    // position.z = 1;
    // Tensor newPositionTensor = RotationMatrix * position;
    // Vector3d newPosition = (Vector3d)newPositionTensor;
    // newPosition = newPosition + pivot;
    // return newPosition;

    Vector3d radius = position - pivot;
    // Moves perpendiculary to the radius vector. The movement is normalized and multiplied by rotation speed and the delta time
    Vector3d newPosition = position + radius.perpendicularClockwise().normalized() * _rotationSpeed * dt;
    return newPosition;
}



std::vector <Node*> Starfield::getStars()
{
    return _stars;
}
