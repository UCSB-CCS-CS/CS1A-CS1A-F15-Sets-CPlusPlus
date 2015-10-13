
#include "set.h"
#include <gtest/gtest.h>
using std::string;

TEST(SetTests, EmptySetToString) {
  Set x;
  EXPECT_EQ(string("{}"), x.toString());
}

TEST(SetTests, OneElementSet) {
  Set x({5});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{5}"), x.toString());
}

TEST(SetTests, TwoElemInOrder) {
  Set x({5,6});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{5,6}"), x.toString());
}

TEST(SetTests, TwoElemOutOfOrder) {
  Set x({5,4});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{4,5}"), x.toString());
}

TEST(SetTests, DuplicateTwoShouldGiveSingletonSet) {
  Set x({5,5});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{5}"), x.toString());
}

#if 0

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

#endif

