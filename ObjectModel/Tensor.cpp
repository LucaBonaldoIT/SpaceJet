#include "Tensor.hpp"
#include <string>
#include <iostream>
#include <math.h>

Tensor::Tensor(size_t _rows, size_t _columns)
{
    rows = _rows;
    columns = _columns;

    // Physically set tensor size
    tensor.resize(rows);
    for (auto & row : tensor)
    {
        // Set each row with columns number
        row.resize(columns);
    }
}

std::string Tensor::toString()
{
    std::string str;
    for (auto &row : tensor)
    {
        for (Point point : row)
        {
            str += (std::to_string(point) + " ");
        }
        str += "\n";
    }
    return str;

}

void Tensor::resize(size_t new_rows, size_t new_columns)
{
    /*Resizing the tensor internal structure is not big deal as
      resizing vector is safe - data is kept (obviusly elements
      cut from the tensor is lost forever.)
      tensor.resize(new_rows);
    */
    for (auto it = tensor.begin(); it != tensor.end(); it++)
    {
        it->resize(new_columns);
    }
}

Tensor Tensor::operator*(const Tensor& other) const
{
    if (this->columns != other.rows)
    {
        throw TensorOperationException("First tensor's number of columns must equals second tensor's number of rows.");
    }
    
    Tensor product(this->rows, other.columns);
    for (int r = 0; r < this->rows; r++)
    {
        for (int c = 0; c < other.columns; c++)
        {
            // Row Vector - Column Vector multiplication
            for (int i = 0; i < other.rows; i++)
            {
                //Point first = this->tensor.at(r).at(i);
                //Point second = other.tensor.at(i).at(c);
                //product.tensor.at(r).at(c) += (first*second);
                
                Point first = this->at(r, i);
                Point second = other.at(i, c);
                product.at(r, c) += (first*second);
            }
        }
    }

    return product;
}

Tensor Tensor::operator*(const Tensor& other)
{
    // Using const version of operator*. this is dereferenced after const_cast
    return (*const_cast<const Tensor*>(this)) * other;
}

Tensor Tensor::operator*(const Vector3d& other) const
{
    // Get column vector equivalent before multiplication
    Tensor otherColumn = Tensor::getColumnVector3d(other);
    return (*this) * otherColumn;
}

Tensor Tensor::operator*(const Vector3d& other)
{
    // Using const version of operator*. this is dereferenced after const_cast
    return (*const_cast<const Tensor*>(this)) * other;
}


Tensor Tensor::operator+(const Tensor& other) const
{
    if (this->columns != other.columns or this->rows != other.rows)
    {
        throw TensorOperationException("Tensors' layouts must coincide.");
    }
    
    Tensor sum(this->rows, this->columns);

    // Sum element by element
    for (size_t r = 0; r < this->rows; r++)
    {
        for (size_t c = 0; c < other.columns; c++)
        {
            sum.at(r, c) = this->at(r, c) + other.at(r, c);
        }
    }

    return sum;
}

Tensor Tensor::operator+(const Tensor& other)
{
    // Using const version of operator+. this is dereferenced after const_cast
    return (*const_cast<const Tensor*>(this)) + other;
}

Tensor Tensor::operator-(const Tensor& other) const
{
    return (*this) + (other * -1);
}

Tensor Tensor::operator-(const Tensor& other)
{
    return (*this) + (other * -1);
}

Tensor Tensor::operator*(const Point& other) const
{
    if (other == 0)
    {
        // Returns null tensor
        return Tensor(this->rows, this->columns);
    }

    Tensor result(this->rows, this->columns);
    for (size_t r = 0; r < this->rows; r++)
    {
        for (size_t c = 0; c < this->columns; c++)
        {
            //std::cout << r << " " << c << std::endl;
            //result.tensor.at(r).at(c) = this->tensor.at(r).at(c) * other;
            result.at(r, c) = this->at(r, c) * other;
        }
    }
    return result;
}

Tensor Tensor::operator*(const Point& other)
{
    // Using const version of operator*. this is dereferenced after const_cast
    return (*const_cast<const Tensor*>(this)) * other;
}

Tensor Tensor::operator/(const Point& other) const
{
    return (*this) * (1/other);
}

Tensor Tensor::operator/(const Point& other)
{
    return (*this) * (1/other);
}


Tensor Tensor::transposed()
{
    // Rows and columns size inverted
    Tensor _transposed(this->columns, this->rows);

    for (int r = 0; r < this->rows; r++)
    {
        // Puts this' row to _transposed's column
        for (int c = 0; c < this->columns; c++)
        {
            _transposed.at(c, r) = this->at(r, c);
        }
    }
    return _transposed;
}

Tensor Tensor::getRowVector3d(Vector3d vector)
{
    Tensor rowVector(1, 3);
    rowVector.at(0, 0) = vector.x;
    rowVector.at(0, 1) = vector.y;
    rowVector.at(0, 2) = vector.z;
    return rowVector;
}

Tensor Tensor::getColumnVector3d(Vector3d vector)
{
    return Tensor::getRowVector3d(vector).transposed();
}

Tensor Tensor::getIdentity(size_t size)
{
    Tensor identity(size, size);
    for (size_t i = 0; i < size; i++)
    {
        identity.at(i, i) = 1;
    }
    return identity;
}

Tensor Tensor::getRotationMatrix3d(const float degree)
{
    Tensor rotationMatrix(3, 3);
    rotationMatrix.at(0, 0) = cos(degree);
    rotationMatrix.at(0, 1) = -sin(degree);
    rotationMatrix.at(1, 0) = sin(degree);
    rotationMatrix.at(1, 1) = cos(degree);
    rotationMatrix.at(2, 2) = 1;

    return rotationMatrix;
}
