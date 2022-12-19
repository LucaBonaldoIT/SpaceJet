#ifndef STARFIELD_H
#define STARTFIEL_D

#include <vector>
#include "Node.hpp"
#include "Star.hpp"

class Starfield
{

    private:

    static inline int STAR_NUM = 150;

    static inline std::vector <Node*> _stars;

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

    static void updateStars()
    {
        for (int i = 0; i < STAR_NUM; i++)
        {
            auto pos = _stars[i]->getPosition() * 1.0004;

            if(pos.x > 1280 || pos.y > 720)
            {
                pos.x = rand() % 1280;
                pos.y = rand() % 720;    
                pos.z = 1280;   
            }
             
            _stars[i]->setPosition(pos);
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