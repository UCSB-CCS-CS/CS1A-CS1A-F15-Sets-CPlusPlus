#ifndef _SET_H_
#define _SET_H_


#include <string>
using std::string;

class Set {

public:
  string toString() const;
  Set add(int newMember) const;
};

#endif // _SET_H_ 
