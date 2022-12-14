#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <vector>

typedef float Point;

class Vector
{
    private:
        std::vector<Point> data;

    public:


        Vector(int size)
        {
            data.resize(size);
        }
        
        Vector(Point _x, Point _y, Point _z)
        {
            data.resize(3);
            data.at(0) = _x;
            data.at(1) = _y;
            data.at(2) = _z;
        }

        inline size_t size(){return data.size();}

        inline size_t size() const {return data.size();}

        inline Point module() const
        {
            return sqrt(this->energy());
        }

        inline Point energy() const
        {
            Point _energy = 0.0f;
            for (Point p : data)
            {
                _energy += (p*p);
            }
            return _energy;
        }

        // ----------- Operator Overloads -----------

        Vector operator+(const Vector& other) const
        {
            if (this-> size() != other.size())
            {
                // Exc
            }

            Vector sum(this->size());
            for (int i = 0; i < this->size(); i++)
            {
                sum.data.at(i) = this->data.at(i) + other.data.at(i);
            }
            return sum;
        }

        Vector operator+(const Vector& other)
        {
            // Using const version of operator+
            // (https://stackoverflow.com/questions/856542/elegant-solution-to-duplicate-const-and-non-const-getters)
            return const_cast<const Vector*>(this)->operator+(other); // Sicuro si può scrivere usando */+- usando dereference
        }

        Vector operator*(const Point& other) const
        {
            Vector result(this->size());
            for (int i = 0; i < this->size(); i++)
            {
                result.data.at(i) = this->data.at(i) * other;
            }
            return result;
        }

        Vector operator*(const Point& other)
        {
            // Using const version of operator+
            return const_cast<const Vector*>(this)->operator*(other);
        }

        Vector operator-(const Vector& other) const
        {
            return *this + other * (-1);
        }

        Vector operator-(const Vector& other)
        {
            // Using const version of operator+
            return const_cast<const Vector*>(this)->operator+(other*(-1));
        }

        Vector operator/(const Point& other) const
        {
            return *this * (1/other);
        }

        Vector operator/(const Point& other)
        {
            // Using const version of operator+
            return const_cast<const Vector*>(this)->operator/(other);
        }

};

#endif