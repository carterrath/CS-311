// CS311 Yoshii
// HW3P2 Instruction: Inherit everything publicly from llist
// Put only the following in class slist.h 
//    inheriting everything from llist.h
//
// Then create slist.cpp with only the following functions
// Complete all ** parts 
//=================================================
// HW#: HW3P2 slist
// Name: Carter Rath
// Compiler: g++
// File: header file slist.h
//=================================================

#include "llist.h"  // for includes

class slist : public llist
{

 public:
  
  slist();   // constructor. cout "in slist constructor".
             // Make it do nothing else.
             // Experiment and see what happens.
             // Taking this out completely would not work.
             // But note that there is no destructor.
             // PLEASE DO NOT delete the couts in slist and llist
             // constructors and destructors for HW6!!!!!
  
  // PURPOSE: serach through the list to see if any node contains the key. If so, return its position (>=1). Otherwise, return 0.
  // PARAMETER: The element that the function needs to find in the list.
  int search(el_t);
  // search through the list to see if any node contains the key.
  // If so, return its position (>=1). Otherwise, return 0.
  
  // PURPOSE: Throw OutOfRange for bad pos. Use moveTo to go to the pos. Go to the Ith node (if I is between 1 and Count) and replace the element there with the new element.
  // PARAMETER: The element to replace the existing element and the position of the node pointing to the element.  
  void replace(el_t,  int);
  // go to the Ith node (if I is between 1 and Count) and 
  // replace the element there with the new element. 
  // If I was an illegal value, throw OutOfRange 
  
  // PURPOSE: Allow L1 == L2 in the client: a regular == cannot compare the two linked lists
  // PARAMETER: this-> pointer represents L1 and OtherOne represents L2

  bool operator==(const slist&);
  // checks to see of the two lists look the same
    

};
