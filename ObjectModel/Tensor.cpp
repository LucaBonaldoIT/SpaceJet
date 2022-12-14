#include "Tensor.hpp"
#include <string>
#include <iostream>

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
    tensor.resize(new_rows);
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
                Point first = this->tensor.at(r).at(i);
                Point second = other.tensor.at(i).at(c);

                product.tensor.at(r).at(c) += (first*second);
            }
        }
    }

    return product;
}

Tensor Tensor::operator*(const Tensor& other)
{
    // Using const version of operator*
    return const_cast<const Tensor*>(this)->operator*(other);
}

Tensor Tensor::operator+(const Tensor& other) const
{
    if (this->columns != other.columns or this->rows != other.rows)
    {
        throw TensorOperationException("Tensors' layouts must coincide.");
    }
    
    Tensor sum(this->rows, this->columns);
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
    // Using const version of operator+
    return const_cast<const Tensor*>(this)->operator+(other);
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
    return const_cast<const Tensor*>(this)->operator*(other);
}


Tensor Tensor::transposed()
{
    // Rows and columns inverted
    Tensor _transposed(this->columns, this->rows);

    for (int r = 0; r < this->rows; r++)
    {
        for (int c = 0; c < this->columns; c++)
        {
            _transposed.at(c, r) = this->at(r, c);
        }
    }
    return _transposed;
}