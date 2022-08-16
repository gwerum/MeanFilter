#include <iostream>
#include <vector>
#include <filter.hpp>

int main()
{
    std::vector<int> measurements{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};    
    MeanFilter<int, 10> filter;

    while(!measurements.empty())
    {
        filter.receive(std::move(measurements.back()));
        measurements.pop_back();
    }

    std::cout << "Measurements received: " << filter << std::endl;
    std::cout << "Mean of measurements: " << filter.getMean() << std::endl;

    return 0;
}