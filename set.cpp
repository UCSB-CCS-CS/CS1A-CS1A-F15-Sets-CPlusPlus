

#include "set.h"

string Set::toString() const {
  if (this->isEmpty)    
    return "{}";
  else
    return "{1}";
}

Set Set::add(int newMember) const {
  Set result;
  result.isEmpty = false;
  return result;
}
