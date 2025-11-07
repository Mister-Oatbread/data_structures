#include <gtest/gtest.h>

// Basic assertion test, to see if tests run at all
TEST(BaseTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
