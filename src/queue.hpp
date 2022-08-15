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
    template<size_t U>
    FixedSizeQueue(T (&arr)[U]);

    // Methods
    template<typename... Elements>
    void emplace(Elements&&... elements);
    void push(T const& element);
    void push(T&& element);
    T operator[] (size_t index) const;
    T& operator[] (size_t index);
    size_t size() const { return curr_size_;};
};

template<typename T, size_t N>
template<size_t U>
inline FixedSizeQueue<T,N>::FixedSizeQueue(T (&arr)[U]) {
    for(size_t i{0}; i<U; ++i)
    {
        emplace(std::move(arr[i]));
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
template<typename... Elements>
inline void FixedSizeQueue<T,N>::emplace(Elements&&... elements) {
    data_[curr_idx_] = T(std::forward<Elements>(elements)...);
    increaseIndex();
    increaseSize();
}

template<typename T, size_t N>
inline void FixedSizeQueue<T,N>::push(T const& element) {
    emplace(element);
}

template<typename T, size_t N>
inline void FixedSizeQueue<T,N>::push(T&& element) {
    emplace(std::move(element));
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

template<typename T, size_t N>
inline std::ostream& operator<< ( std::ostream& os, FixedSizeQueue<T,N> const& queue )
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
