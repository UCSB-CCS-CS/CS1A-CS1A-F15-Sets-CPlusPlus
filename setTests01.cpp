
#include "set.h"
#include <gtest/gtest.h>
using std::string;

TEST(SetTests, EmptySetToString) {
  Set x;
  EXPECT_EQ(string("{}"), x.toString());
}

TEST(SetTests, EmptySetContainsNothing) {
  Set x;
  EXPECT_EQ(false, x.contains(3));
}

TEST(SetTests, OneElementSet) {
  Set x({5});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{5}"), x.toString());
}

TEST(SetTests, Singleton5Contains5) {
  Set x({5});
  EXPECT_EQ(true, x.contains(5));
}


TEST(SetTests, TwoElemInOrder) {
  Set x({5,6});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{5,6}"), x.toString());
}

TEST(SetTests, TwoElemInOrderContainsEach) {
  Set x({5,6});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{5,6}"), x.toString());
  EXPECT_TRUE(x.contains(5));
  EXPECT_TRUE(x.contains(6));
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

TEST(SetTests, BiggerDuplicateDetection) {
  Set x({3,4,4});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{3,4}"), x.toString());
}

TEST(SetTests, ThreeElemInOrderSet) {
  Set x({4,5,6});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{4,5,6}"), x.toString());
}

#if 0

TEST(SetTests, ThreeElemInOrderSet) {
  Set x({4,5,6});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{4,5,6}"), x.toString());
}

TEST(SetTests, BiggerDuplicateDetectionPartFour) {
  Set x({4,4,4,4,3,3,4,3,6});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{3,4,6}"), x.toString());
}


TEST(SetTests, BiggerDuplicateDetection) {
  Set x({3,3,4,4,3,3,4,3});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{3,4}"), x.toString());
}

TEST(SetTests, BiggerDuplicateDetectionPartDeux) {
  Set x({4,4,4,4,3,3,4,3});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{3,4}"), x.toString());
}

TEST(SetTests, BiggerDuplicateDetectionPartTres) {
  Set x({5,4,4,4,4,4});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{4,5}"), x.toString());
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

#endif

