
#include <string>
using std::string;

#include <gtest/gtest.h>

class Set {

public:
  string toString() {
    return "{}";
  }
};

TEST(SetTest, Static) {
  Set x;
  EXPECT_EQ(string("{}"), x.toString());
}
