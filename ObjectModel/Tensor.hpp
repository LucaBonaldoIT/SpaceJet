#ifndef TENSOR_H   
#define TENSOR_H

#include <vector>
#include <string>

#include "Vector2d.hpp"
#include "Vector3d.hpp"
#include "Types.hpp"

namespace math
{
    typedef Vector2d TensorSize;


    class Tensor
    {
        private:
            size_t rows;
            size_t columns;
            std::vector<std::vector<Point>> tensor;


        public:
            Tensor(size_t, size_t);
            TensorSize getSize(){return TensorSize(rows, columns);}
            void resize(size_t new_rows, size_t new_columns);
            Point at(size_t row, size_t column) const {return tensor.at(row).at(column);}
            Point& at(size_t row, size_t column) {return tensor.at(row).at(column);}; // const_cast trick cannot work (const value -> reference conversion)

            Tensor transposed();

            // ----------- Tensor - Tensor operations -----------
            Tensor operator*(const Tensor& other)  const;
            Tensor operator*(const Tensor& other);
            Tensor operator*(const Vector3d& other) const;
            Tensor operator*(const Vector3d& other);
            Tensor operator+(const Tensor& other) const;
            Tensor operator+(const Tensor& other);
            Tensor operator-(const Tensor& other) const;
            Tensor operator-(const Tensor& other);

            // ----------- Tensor - Scalar operations -----------
            Tensor operator*(const Point& other) const;
            Tensor operator*(const Point& other);
            Tensor operator/(const Point& other) const;
            Tensor operator/(const Point& other);

            static Tensor getRowVector3d(Vector3d);
            static Tensor getColumnVector3d(Vector3d);
            static Tensor getIdentity(size_t);
            static Tensor getRotationMatrix3d(const float);

            // ----------- Cast operators -----------
            operator Vector3d() const;

            std::string toString();


    };

    class TensorOperationException : public std::exception 
    {
        private:
            char * message;

        public:
            TensorOperationException(char * msg) : message(msg){}
            char* what () {return message;}
    };

}

#endif