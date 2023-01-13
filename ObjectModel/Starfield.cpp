#include "Starfield.hpp"

//const Tensor Starfield::RotationMatrix = Tensor::getRotationMatrix3d(_rotationSpeed);


// Adapted original name for lazynessssssssssssssss
void Starfield::updateField(DeltaTime dt)
{
    this->updateStars(dt);
}

std::vector<Node*> Starfield::getFieldNodes()
{
    return this->getStars();
}

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

    for (auto it = _stars.begin(); it != _stars.end(); it++)
    {
        Node* star = (*it);
        math::Vector3d starInitialPosition = star->getPosition();
        math::Vector3d starFinalPosition;

        // Star expansion
        math::Vector3d starExpansion = starInitialPosition - _rotationPivot;   // Distance vector from the rotation point
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

math::Vector3d Starfield::rotateAround(math::Vector3d position, math::Vector3d pivot, DeltaTime dt)
{
    // Old rotation code with matrix multiplication
    // position = position - pivot;
    // position.z = 1;
    // Tensor newPositionTensor = RotationMatrix * position;
    // math::Vector3d newPosition = (math::Vector3d)newPositionTensor;
    // newPosition = newPosition + pivot;
    // return newPosition;

    math::Vector3d radius = position - pivot;
    // Moves perpendiculary to the radius vector. The movement is normalized and multiplied by rotation speed and the delta time
    math::Vector3d newPosition = position + radius.perpendicularClockwise().normalized() * _rotationSpeed * dt;
    return newPosition;
}



std::vector <Node*> Starfield::getStars()
{
    return _stars;
}
