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

// Unit test for FixedSizeQueue::emplace(Elements&&... elements)
TEST(QueueTest, Emplace) {
  // Test parametrized constructor
  int expected_values[10] = {1,2,3,4,5,6,7,8,9,10};
  FixedSizeQueue<int, 5> queue;

  // Add 10 values to queue
  for(size_t i{0}; i<10; ++i)
  {
    queue.emplace(expected_values[i]);
  }
  
  // Check if only last 5 values exist in queue
  EXPECT_EQ(5, queue.size());
  for(size_t i{0}; i<queue.size(); ++i)
  {
    EXPECT_EQ(expected_values[i+5], queue[i]);
  }
}