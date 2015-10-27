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

#ifdef DEBUG_MESSAGES
  std::cerr << "I should be adding "
	    << x << " to my set" << std::endl;
#endif
  
  if (head==NULL) {
    head = newSetElemNode(x);
    return;
  }
  
  SetElemNode *p = newSetElemNode(x);

  if ( x  <  head->elem  ) {
    // add new elem before
    p->next = head;
    head = p;
  } else if (head->next == NULL) {
    // add 2nd new elem immediately after head
    head -> next = p;
  } else {
    // My list is of at least size 2.
    // And my new elem goes in between, or at the end.
    if ( x <   head->next->elem  ) {
      // insert in the middle
      p->next = head->next;
      head->next = p;
    } else {
      // insert at the end
      head->next->next = p  ;
    }
  }
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
