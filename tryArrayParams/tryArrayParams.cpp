#include <iostream>
using namespace std;

void printArray(const std::initializer_list<int>& array) {

  cout << "{";

  bool firstTime = true;
  for (auto x : array) { // C++0x foreach loop
    if (firstTime) {
      firstTime = false;
    } else {
      cout << ", ";
    }
    std::cout << x ;
  }
}


int main(void) {
  printArray({4,5,6});
  printArray({2,25,-4,0,23,56,7});
  return 0;
}
