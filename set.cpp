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
    std::cerr << x << " already in set; not added" << std::endl;
    return;
  }

  std::cerr << "I should be adding "
	    << x << " to my set" << std::endl;
  
  if (head==NULL) {
    head = newSetElemNode(x);
    return;
  }

  
  SetElemNode *p = newSetElemNode(x);

  if ( x  <  head->elem  ) {
    // add new elem before
    p->next = head;
    head = p;
  } else {
    // add new elem after
    head -> next = p;
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
