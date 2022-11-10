#include <iostream>
#include <vector>
#include <filter.hpp>

template<typename T, size_t N>
void print(MeanFilter<T,N>& filter)
{
    std::cout << "Measurements received: " << filter << std::endl;
    std::cout << "Mean of measurements: " << filter.getMean() << std::endl;
}

int main()
{
    //std::vector<char> measurements{'a','b','c'};
    std::vector<double> measurements{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};    
    MeanFilter<int, 10> filter;

    for(auto const& measurement: measurements)
    {
        filter.receive(measurement);
        print(filter);
    }

    return 0;
}