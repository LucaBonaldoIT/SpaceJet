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

Tensor Tensor::operator*(const Tensor& other)
{
    if (this->columns != other.rows)
    {
        throw NotMultipliableTensorException("First tensor's number of columns must equals second tensor's number of rows.");
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

