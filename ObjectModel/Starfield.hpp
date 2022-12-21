#ifndef STARFIELD_H
#define STARTFIEL_D

#include <vector>
#include "Node.hpp"
#include "Star.hpp"
#include "Tensor.hpp"

//const Tensor rotationMatrix = Tensor::getRotationMatrix3d(0.0001f);

class Starfield
{

    private:

    static inline int STAR_NUM = 170;

    static inline std::vector <Node*> _stars;
    const static Tensor rotationMatrix;

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

    static Vector3d rotateAround(Vector3d position, Vector3d pivot, const float degrees)
    {
        position = position - pivot;
        position.z = 1;
        Tensor newPositionTensor = rotationMatrix * position;
        Vector3d newPosition(newPositionTensor.at(0, 0), newPositionTensor.at(1, 0), newPositionTensor.at(2, 0));
        newPosition = newPosition + pivot;
        return newPosition;
    }

    static void updateStars()
    {
        for (int i = 0; i < STAR_NUM; i++)
        {
            auto pos = _stars[i]->getPosition() * 1.0001;

            pos = rotateAround(pos, Vector3d(640, 360, 0), 0.00005f);

            //pos = pos - Vector3d(640, 360, 0);

            if(pos.x > 1280 || pos.y > 1280)
            {
                pos.x = rand() % 1280;
                pos.y = rand() % 1280;    
                pos.z = 1280;   
            }
             
            _stars[i]->setPosition(pos);

            // Tensor rotationMatrix = Tensor::getRotationMatrix3d(0.0001f);
            // pos.z = 1;
            // auto new_pos = rotationMatrix * pos;
            // Vector3d new_pos_vector(new_pos.at(0, 0), new_pos.at(1, 0), new_pos.at(2, 0));
            // new_pos_vector = new_pos_vector + Vector3d(640, 360, 0);
            // _stars[i]->setPosition(new_pos_vector);

            pos.z--;
            _stars[i]->setRatio(std::min(3000.0/pos.z, 2.0));

        }
    }

    static std::vector <Node*> getStars()
    {
        return _stars;
    }


};

#endif