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
    static inline float _expansionSpeed = 300.0f;    //1.003
    static inline float _rotationSpeed = 700.0f;
    //static inline float _expansionSpeed = 0;
    const static Tensor RotationMatrix;
    static inline Vector3d _rotationPivot;
    
    static const size_t BorderSpawnWidth = 200;  // "Border" of spawn window
    static const size_t BorderSpawnHeight = 100; 
    

    public:

    Starfield()
    {
        
    }

    static void generateStars();

    static Vector3d rotateAround(Vector3d position, Vector3d pivot, DeltaTime dt);
    static void updateStars(DeltaTime dt);

    static std::vector <Node*> getStars();


};

#endif