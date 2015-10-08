#include <iostream>
#include <sstream>

#include "set.h"

string Set::toString() const {
  std::ostringstream oss;
  oss << "{";

  if (this->head!=NULL) {
    oss << this->head->elem;
  
    for (SetElemNode *p=this->head->next; p!=NULL; p=p->next) {
      oss << "," << p->elem;
    }
  }
  oss << "}";
  return oss.str(); 
}

Set Set::add(int newMember) const {
  Set stub;
  return stub;
}
