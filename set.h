#ifndef _SET_H_
#define _SET_H_


#include <string>
using std::string;

class Set {
 private:
  bool isEmpty = true;
  
 public:
  // this is constructor for stuff such as Set x({2,3,4}),
  //  i.e. array literals
  Set (const std::initializer_list<int>& array) { /* stub */ }
  Set () {} ;
  
  string toString() const;
  Set add(int newMember) const;
};

#endif // _SET_H_ 
