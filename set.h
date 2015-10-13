#ifndef _SET_H_
#define _SET_H_

#include <iostream>
#include <string>

class Set {
 private:
  
  struct SetElemNode {
    int elem;
    SetElemNode *next;
  };

  SetElemNode * newSetElemNode(int x) {
    SetElemNode *p=new SetElemNode;
    p->elem = x;
    p->next = NULL;
    return p;
  }

  
  SetElemNode *head = NULL;

  void addElemToSetUnderConstruction(int x);
  
 public:
  // this is constructor for stuff such as Set x({2,3,4}),
  //  i.e. array literals
  Set (const std::initializer_list<int>& array);
  Set () {} ;
  
  std::string toString() const;
  Set add(int newMember) const;
};

#endif // _SET_H_ 
