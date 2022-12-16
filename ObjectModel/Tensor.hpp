#ifndef TENSOR_H   
#define TENSOR_H

#include "Vector2d.hpp"
#include "Vector3d.hpp"
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
        Tensor transposed();
        void resize(size_t new_rows, size_t new_columns);
        Tensor operator*(const Tensor& other)  const;
        Tensor operator*(const Tensor& other);
        Tensor operator+(const Tensor& other) const;
        Tensor operator+(const Tensor& other);
        Tensor operator*(const Point& other) const;
        Tensor operator*(const Point& other);

        Point at(size_t row, size_t column) const {return tensor.at(row).at(column);}
        Point& at(size_t row, size_t column) {return tensor.at(row).at(column);}; // const_cast trick cannot work (const value -> reference conversion)

        static Tensor getRowVector3d(Vector3d);
        static Tensor getColumnVector3d(Vector3d);

};

class TensorOperationException : public std::exception 
{
    private:
        char * message;

    public:
        TensorOperationException(char * msg) : message(msg){}
        char* what () {return message;}
};


#endif