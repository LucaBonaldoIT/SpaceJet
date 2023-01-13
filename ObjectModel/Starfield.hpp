#ifndef STARFIELD_H
#define STARTFIEL_D

#include <vector>
#include <algorithm>
#include <string>

#include "Common.hpp"
#include "Node.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include "Field.hpp"

class Starfield : public Field
{

    private:

    int STAR_NUM = 150;

    std::vector <Node*> _stars;
    float _expansionSpeed = 300.0f;    //1.003
    float _rotationSpeed = 700.0f;
        //const static Tensor RotationMatrix;
    math::Vector3d _rotationPivot;
    
    const size_t BorderSpawnWidth = 200;  // "Border" of spawn window
    const size_t BorderSpawnHeight = 100; 
    

    public:

    Starfield()
    {
        this->generateStars();
        Logger::log("Starfield instantiated.");
    }

    void generateStars();

    math::Vector3d rotateAround(math::Vector3d position, math::Vector3d pivot, DeltaTime dt);
    virtual void updateField(DeltaTime dt);
    virtual std::vector<Node*> getFieldNodes();
    void updateStars(DeltaTime dt);

    std::vector <Node*> getStars();


};

#endif