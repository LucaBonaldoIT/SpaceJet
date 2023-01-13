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

    static inline int STAR_NUM = 0;

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

    static void generateStars();

    static Vector3d rotateAround(Vector3d position, Vector3d pivot);
    static void updateStars();

    static std::vector <Node*> getStars();


};

#endif