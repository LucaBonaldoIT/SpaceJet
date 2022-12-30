#ifndef STARFIELD_H
#define STARTFIEL_D

#include <vector>
#include <algorithm>

#include "Common.hpp"
#include "Node.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include <string>

class Starfield
{

    private:

    static inline int STAR_NUM = 150;

    static inline std::vector <Node*> _stars;
    static inline float _expansionSpeed = 1.003;
    //static inline float _expansionSpeed = 0;
    static inline float _rotationSpeed = 0.0006f;
    const static Tensor RotationMatrix;
    static inline Vector3d _rotationPivot;
    
    static const size_t BorderSpawnWidth = 200;  // "Border" of spawn window
    static const size_t BorderSpawnHeight = 100; 
    

    public:

    Starfield()
    {
        
    }

    static void generateStars() {
        for(int i = 0; i < STAR_NUM; i++)
        {
            _stars.push_back(new Star());
        }
    }

    static Vector3d rotateAround(Vector3d position, Vector3d pivot)
    {
        position = position - pivot;
        position.z = 1;
        Tensor newPositionTensor = RotationMatrix * position;
        Vector3d newPosition = (Vector3d)newPositionTensor;
        newPosition = newPosition + pivot;
        return newPosition;
    }

    static void updateStars()
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

    static std::vector <Node*> getStars()
    {
        return _stars;
    }


};

#endif