#include <algorithm>
#include <ostream>

template<typename T, size_t N>
class FixedSizeQueue
{
private:
    T data_[N];
    int curr_idx_{};
    size_t curr_size_{};
    void increaseIndex();
    void increaseSize();
    int convertToArrayIndex( int virtual_index ) const;
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
    T operator[] (int index) const;
    T& operator[] (int index);
    size_t size() const { return curr_size_;};
};

template<typename T, size_t N>
template<size_t U>
FixedSizeQueue<T,N>::FixedSizeQueue(T (&arr)[U]) {
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
inline T FixedSizeQueue<T,N>::operator[] (int index) const {
    return data_[convertToArrayIndex(index)];
}

template<typename T, size_t N>
inline T& FixedSizeQueue<T,N>::operator[] (int index) {
    return data_[convertToArrayIndex(index)];
}

template<typename T, size_t N>
inline int FixedSizeQueue<T,N>::convertToArrayIndex( int virtual_index ) const {
    return ((curr_idx_ + virtual_index ) % size());
}

template<typename T, size_t N>
inline std::ostream& operator<< ( std::ostream& os, FixedSizeQueue<T,N> const& queue )
{
    os << "[";
    for(size_t i{0}; i<queue.size(); ++i)
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
