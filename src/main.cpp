#include <iostream>
#include <queue.hpp>

int main()
{
    int constexpr size{15};
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    FixedSizeQueue<int, 10> queue;

    std::cout << "Array: [";
    for(int i{0}; i<size; ++i)
    {
        queue.push(arr[i]);
        if(i != (size - 1))
        {
            std::cout << arr[i] << ", ";
        }
        else
        {
            std::cout << arr[i] << "]\n";
        }
    }

    std::cout << "Queue: " << queue << std::endl;

    return 0;
}