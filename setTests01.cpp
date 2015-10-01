
#include "set.h"
#include <gtest/gtest.h>

TEST(SetTest, Static) {
  Set x;
  EXPECT_EQ(string("{}"), x.toString());
}
