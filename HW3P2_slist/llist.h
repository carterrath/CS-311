//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Carter Rath
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //returns true if front and rear are both pointing to NULL and Count is 0
  bool isEmpty();
    
  //display each element of the list starting from Front, enclosed in [] and following by endl. E.g. [ 1 2 3 ] blanks between elements horizontally
  void displayAll();

  //add a new node at the front and puts NewNum in the Elem field of this new node. Count is updated.
  void addFront(el_t);
    
  //add a new node at the rear and puts a NewNum in the Elem field of this new node. Count is updated.
  void addRear(el_t);

  //give back the front node element through OldNum (pass by reference) and also remove the front node. Count is updated.
  void deleteFront(el_t&);
  
  //---------------------------------------
    
  //give back the rear node element through OldNum (pass by reference) and also remove the rear node. Count is updated.
  void deleteRear(el_t&);
    
  //will delete the Ith node (I starts out at 1). Count is updated.
  void deleteIth(int, el_t&);  // calls moveTo

  //will add right before the Ith node. Count is updated.
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
