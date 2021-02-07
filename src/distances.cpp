#include "distances.hpp"
#include <cmath>
#include <iostream>

double euclidean_distance(std::vector<double> point_a, std::vector<double> point_b)
{
    unsigned size = (unsigned)point_a.size();
    if (size != point_b.size())
        throw std::runtime_error("Points with different number of dimensions...");

    double summation = 0.0;

    for (unsigned i = 0; i < size; i++)
    {
        summation += pow((point_a[i] - point_b[i]), 2.0);
    }

    return sqrt(summation);
}

double manhattan_distance(std::vector<double> point_a, std::vector<double> point_b)
{
    unsigned size = (unsigned)point_a.size();
    if (size != point_b.size())
        throw std::runtime_error("Points with different number of dimensions...");

    double summation = 0.0;

    for (unsigned i = 0; i < size; i++)
    {
        summation += std::abs(point_a[i] - point_b[i]);
    }

    return summation;
}