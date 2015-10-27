#include <iostream>
#include <sstream>

#include "set.h"
using std::string;

bool Set::contains(int x) {

  for (SetElemNode *p=head ; p!=NULL ; p=p->next ) {
    if (p->elem == x)
      return true;
  }

  return false;

}

void Set::addElemToSetUnderConstruction(int x) {

  if ( this->contains(x) ) {
#ifdef DEBUG_MESSAGES
    std::cerr << x << " already in set; not added" << std::endl;
#endif
    return;
  }

  SetElemNode *p = newSetElemNode(x);
  
#ifdef DEBUG_MESSAGES
  std::cerr << "I should be adding "
	    << x << " to my set" << std::endl;
#endif
  
  if (head==NULL) {
    head = p;
    return;
  }

  if (x < head->elem) {
    p->next = head;
    head = p;
    return;
  }
  
  // Find ib, a pointer to element that we need
  // to insert x in front of.  trailIb will follow
  // one node behind.
  // We know that x is not in the list; we already checked.
  // We know that x doesn't go at beginning of list.
  
  SetElemNode *trailib = NULL;
  SetElemNode *ib;
  for (ib=head; (ib!=NULL) && (ib->elem < x); ib=ib->next) {
    // do something with ib;
    trailib = ib;
  }
  p->next = ib;
  trailib->next = p;
}


Set::Set (const std::initializer_list<int>& array) {
  for (int elem: array) {
    this->addElemToSetUnderConstruction(elem);
  }
}

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
