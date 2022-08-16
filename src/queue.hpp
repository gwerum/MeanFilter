#include <algorithm>
#include <ostream>
#include <stdexcept>

template<typename T, size_t N>
class FixedSizeQueue
{
private:
    T data_[N]{};
    size_t curr_idx_{};
    size_t curr_size_{};
    void increaseIndex();
    void increaseSize();
    size_t convertToBufferIndex( size_t virtual_index ) const;
public:
    // Constructors
    FixedSizeQueue() = default;
    ~FixedSizeQueue() = default;
    template<size_t ARR_SIZE>
    FixedSizeQueue(T (&arr)[ARR_SIZE]);

    // Methods
    template<class... Args>
    void emplace_back(Args&&... args);
    void push_back(T const& element);
    void push_back(T&& element);
    T operator[] (size_t index) const;
    T& operator[] (size_t index);
    size_t size() const { return curr_size_;};
    template<typename _T, size_t _N>
    friend std::ostream& operator<<( std::ostream& os, FixedSizeQueue<_T,_N> const& queue);
};

template<typename T, size_t N>
template<size_t ARR_SIZE>
inline FixedSizeQueue<T,N>::FixedSizeQueue(T (&arr)[ARR_SIZE]) {
    for(size_t i{0}; i<ARR_SIZE; ++i)
    {
        push_back(arr[i]);
    }
};

template<typename T, size_t N>
inline void FixedSizeQueue<T,N>::increaseIndex() {
    curr_idx_++;
    curr_idx_ = curr_idx_ % N;
}

template<typename T, size_t N>
inline void FixedSizeQueue<T,N>::increaseSize() {
    curr_size_++;
    curr_size_ = std::min(curr_size_, N);
}

template<typename T, size_t N>
template<class... Args>
inline void FixedSizeQueue<T,N>::emplace_back(Args&&... args) {
    data_[curr_idx_] = T(std::forward<Args>(args)...);
    increaseIndex();
    increaseSize();
}

template<typename T, size_t N>
inline void FixedSizeQueue<T,N>::push_back(T const& element) {
    emplace_back(element);
}

template<typename T, size_t N>
inline void FixedSizeQueue<T,N>::push_back(T&& element) {
    emplace_back(std::move(element));
}

template<typename T, size_t N>
inline T FixedSizeQueue<T,N>::operator[] (size_t index) const {
    if (index >= N)
        throw std::out_of_range("Accessing queue at index out-of-range");
    return data_[convertToBufferIndex(index)];
}

template<typename T, size_t N>
inline T& FixedSizeQueue<T,N>::operator[] (size_t index) {
    if (index >= N)
        throw std::out_of_range("Accessing queue at index out-of-range");
    return data_[convertToBufferIndex(index)];
}

template<typename T, size_t N>
inline size_t FixedSizeQueue<T,N>::convertToBufferIndex( size_t virtual_index ) const {
    return ((curr_idx_ + virtual_index ) % size());
}

template<typename _T, size_t _N>
std::ostream& operator<<( std::ostream& os, FixedSizeQueue<_T,_N> const& queue)
{
    os << "[";
    for(size_t i{0}; i<queue.size(); ++i)
    {
        os << std::to_string(queue[i]);
        if(i != (queue.size() - 1))
        {
            os << ",";
        }
        else
        {
            os << "]";
        }
    }
    return os;
}
