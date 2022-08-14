#include <gtest/gtest.h>
#include <queue.hpp>

// Unit test for default initialization of FixedSizeQueue
TEST(QueueTest, InitTest) {
  // Expect true to be TRUE
  FixedSizeQueue<int, 10> queue;
  EXPECT_EQ(0, queue.size());
}