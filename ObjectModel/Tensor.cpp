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
