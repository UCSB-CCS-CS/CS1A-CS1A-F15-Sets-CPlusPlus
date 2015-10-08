
#include "set.h"
#include <gtest/gtest.h>

TEST(SetTests, EmptySetToString) {
  Set x;
  EXPECT_EQ(string("{}"), x.toString());
}

TEST(SetTests, SingletonOneToString) {
  Set x;
  Set y=x.add(1);
  EXPECT_EQ(string("{1}"), y.toString());
}

TEST(SetTests, BiggerSet) {
  Set x({3,7,4,9});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{3,4,7,9}"), x.toString());
}
