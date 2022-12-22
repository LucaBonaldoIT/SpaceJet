#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <climits>
#include <random>

class Random
{
    private:

    static inline std::random_device rng = std::random_device();

    public:

    static int getSingleInt(int minValue, int maxValue)
    {
        return std::uniform_int_distribution(minValue, maxValue)(rng);
    }
    static int getSingleInt(int maxValue) { return getSingleInt(0, maxValue); }
    static int getSingleInt() { return getSingleInt(0, INT_MAX); }


    // static std::vector<int> getManyInt();

    
    static double getSingleDouble(double minValue, double maxValue)
    {
        return std::uniform_real_distribution(minValue, maxValue)(rng);
    }
    static double getSingleDouble(double maxValue) { return getSingleDouble(0, maxValue); }
    static double getSingleDouble() { return getSingleDouble(0, __DBL_MAX__); }

    // static std::vector<double> getManyDouble();

};

#endif