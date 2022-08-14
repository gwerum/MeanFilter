#include <algorithm>
#include <ostream>

template<typename T, int N>
class FixedSizeQueue
{
private:
    T data_[N];
    int curr_idx_{};
    int curr_size_{};
    void increaseIndex();
    void increaseSize();
    int convertToArrayIndex( int virtual_index ) const;
public:
    FixedSizeQueue() = default;
    ~FixedSizeQueue() = default;
    void push(T const& element);
    T operator[] (int index) const;
    T& operator[] (int index);
    int size() const { return curr_size_;};
};

template<typename T, int N>
inline void FixedSizeQueue<T,N>::increaseIndex() {
    curr_idx_++;
    curr_idx_ = curr_idx_ % N;
}

template<typename T, int N>
inline void FixedSizeQueue<T,N>::increaseSize() {
    curr_size_++;
    curr_size_ = std::min(curr_size_, N);
}

template<typename T, int N>
inline void FixedSizeQueue<T,N>::push(T const& element) {
    data_[curr_idx_] = element;
    increaseIndex();
    increaseSize();
}

template<typename T, int N>
inline T FixedSizeQueue<T,N>::operator[] (int index) const {
    return data_[convertToArrayIndex(index)];
}

template<typename T, int N>
inline T& FixedSizeQueue<T,N>::operator[] (int index) {
    return data_[convertToArrayIndex(index)];
}

template<typename T, int N>
inline int FixedSizeQueue<T,N>::convertToArrayIndex( int virtual_index ) const {
    return ((curr_idx_ + virtual_index ) % size());
}

template<typename T, int N>
inline std::ostream& operator<< ( std::ostream& os, FixedSizeQueue<T,N> const& queue )
{
    os << "[";
    for(int i{0}; i<queue.size(); ++i)
    {
        T const value{queue[i]};
        os << value;
        if(i != (queue.size() - 1))
        {
            os << ", ";
        }
        else
        {
            os << "]";
        }
    }
    return os;
}
