#ifndef TENSOR_H   
#define TENSOR_H

#include "Vector2d.hpp"
#include <vector>
#include <string>

typedef Vector2d TensorSize;
typedef float Point;


class Tensor
{
    private:
        size_t rows;
        size_t columns;
        std::vector<std::vector<Point>> tensor;


    public:
        Tensor(size_t, size_t);
        TensorSize getSize(){return TensorSize(rows, columns);}
        std::string toString();
};


#endif