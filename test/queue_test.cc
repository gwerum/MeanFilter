#include <gtest/gtest.h>
#include <queue.hpp>

// Unit test for default initialization of FixedSizeQueue
TEST(QueueTest, DefaultConstructor) {
  // Test unitialized queue
  FixedSizeQueue<int, 10> queue;
  EXPECT_EQ(0, queue.size());
}

// Unit test for array initialization of FixedSizeQueue
TEST(QueueTest, ParametrizedConstructor) {
  // Test parametrized constructor
  int arr[5] = {1,2,3,4,5};
  FixedSizeQueue<int, 10> queue{arr};
  EXPECT_EQ(5, queue.size());
  
  for(size_t i{0}; i<5; ++i)
  {
    EXPECT_EQ(arr[i], queue[i]);
  }
}