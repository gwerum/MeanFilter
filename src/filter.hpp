#include <queue.hpp>
#include <ostream>

template<typename T, size_t N>
class MeanFilter
{
private:
    FixedSizeQueue<T,N> measurements_{};
public:
    MeanFilter() = default;
    ~MeanFilter() = default;
    void receive(T measurement);
    double getMean() const;
    template<typename _T, size_t _N>
    friend std::ostream& operator<<(std::ostream& os, MeanFilter<_T,_N> const& filter );
};

template<typename T, size_t N>
inline void MeanFilter<T,N>::receive(T measurement)
{
    measurements_.emplace_back(std::move(measurement));
}

template<typename T, size_t N>
inline double MeanFilter<T,N>::getMean() const
{
    size_t sum{};
    for(size_t i{0}; i<measurements_.size(); ++i)
    {
        sum += measurements_[i];
    }
    double mean{(double)sum/(double)measurements_.size()};
    return mean;
}

template<typename _T, size_t _N>
std::ostream& operator<<(std::ostream& os, MeanFilter<_T,_N> const& filter )
{
    os << filter.measurements_;
    return os;
}