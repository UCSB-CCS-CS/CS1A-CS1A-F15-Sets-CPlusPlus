
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

TEST(SetTests, ThreeElemSetInsertedAs_3_5_1_gives_1_3_5) {
  Set x({3,5,1});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{1,3,5}"), x.toString());
}

TEST(SetTests, ThreeElemSetInsertedAs_3_5_4_gives_3_4_5) {
  Set x({3,5,4});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{3,4,5}"), x.toString());
}

TEST(SetTests, ThreeElemSetInsertedAs_3_5_6_gives_3_5_6) {
  Set x({3,5,6});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{3,5,6}"), x.toString());
}

TEST(SetTests, FourElemSetInsertedAs_2_4_6_1_gives_1_2_4_6) {
  Set x({2,4,6,1});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{1,2,4,6}"), x.toString());
}

TEST(SetTests, FourElemSetInsertedAs_2_4_6_3_gives_2_3_4_6) {
  Set x({2,4,6,3});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{2,3,4,6}"), x.toString());
}

TEST(SetTests, FourElemSetInsertedAs_2_4_6_5_gives_2_4_5_6) {
  Set x({2,4,6,5});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{2,4,5,6}"), x.toString());
}

TEST(SetTests, SevenElemSetInsertedWayOutOfOrder) {
  Set x({50,75,25,37,10,80,5,75,50,15,96,4,52,4,107});
  // Canonical representation is ordered,
  //  even through object itself is not.
  EXPECT_EQ(string("{4,5,10,15,25,37,50,52,75,80,96,107}"),
	    x.toString());
}
