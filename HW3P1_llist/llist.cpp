//CS311 Yoshii FALL21 Linked List class
//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Carter Rath
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 
//PURPOSE: constructor-initialize Front and Rear to be NULL and Count = 0. This does not create any node. The list is empty.
llist::llist()
{ cout << "... in llist constructor..." << endl; 
  Front = Rear = NULL;
  Count = 0; }
//PURPOSE: destructor-while the list is not empty, call deleteFront repeatedly to delete all nodes.
llist::~llist()
{ cout << ".... in llist destructor..." << endl; 
  int temp;
  while (!isEmpty())
    { deleteFront(temp); }
}

//PURPOSE: return true if Front and Rear are both pointing to NULL and Count is 0.
//PARAMETER: No parameters.
bool llist::isEmpty() 
{ if (Front == NULL && Rear == NULL && Count == 0) return true;
  else return false; } // be sure to check all 3 data members

//PURPOSE: display each element of the list starting from the Front, enclosed in [ ] followed by endl. E.g. [ 1 2 3 ] blanks between elements horizontally (special case: if the list is empty, display [ empty ] ).
//PARAMETER: No parameters.
void llist::displayAll() 
{ if (isEmpty()) // special case
    cout << "[ empty ]" << endl;
  else // regular case
    { cout << "[ ";
      Node* P = Front;
      while (P != NULL)
	{ cout << P -> Elem << " ";
	  P = P -> Next; }
      cout << "]" << endl; 
    } 
}  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE: 2 cases-add a new node at the rear. Count is updated. If this is the very first node, create a new node and make Front and Rear point to it.
//PARAMETER: puts NewNum in the Elem field of this new node.
void llist::addRear(el_t NewNum) 
{ if (isEmpty()) //special case
    { Front = new Node;
      Rear = Front;
      Rear -> Elem = NewNum;
      Rear -> Next = NULL; 
    }
  else // regular case
    { Rear -> Next = new Node;
      Rear = Rear -> Next;
      Rear -> Elem = NewNum;
      Rear -> Next = NULL;
    }
  Count++;
} // comment the 2 cases

//PURPOSE: add a new node at the front. Count is updated. If this is the very first node, create a new node and make Front and Rear point to it.
//PARAMETER: puts NewNum in the Elem field of this new Node.
void llist::addFront(el_t NewNum) 
{ if (isEmpty()) // special case
    { Front = new Node;
      Rear = Front;
      Front -> Elem = NewNum;
      Rear -> Next = NULL;
    }
  else // regular case
    { Node* P;
      P = new Node;
      P -> Elem = NewNum;
      P -> Next = Front;
      Front = P;
    }
  Count++;
} // comment the 2 cases

//PURPOSE: remove the front node. Count is updated. If the List is empty, throw an exception. If this is going to make the list empty, remove the front node, count is updated, and make sure bothe the Front and Rear both become NULL.
//PARAMETER: give back the front node element through OldNum (pass by reference).
void llist::deleteFront(el_t& OldNum) 
{ if (isEmpty()) { throw Underflow(); } // error case
  OldNum = Front -> Elem;
  if (Front -> Next == NULL) // special case
    { delete Front; Front = Rear = NULL;
      Count--;
    }
  else // regular case
    { Node* Second = Front -> Next; // know the second node
      delete Front; // delete the Front node
      Front = Second; // Front moves down
      Count--;
    }
} // comment the 3 cases

//PURPOSE: remove the rear node. Count is updated. if empty, throw an exception. If this is going to make the list empty, remove the rear node, count is updated, and make sure both Front and Rear become NULL).
//PARAMETER: give back the rear node element through OldNum (pass by reference).
void llist::deleteRear(el_t& OldNum)
{ if (isEmpty()) { throw Underflow(); }// error case
  OldNum = Rear -> Elem;
  if (Front -> Next == NULL) // special case
    { delete Rear; Front = Rear = NULL; Count--; }
  else // regular case
    { Node* P = Front;
      while (P -> Next != Rear)
	{ P = P -> Next; } // know the previous node
      delete Rear; // delete the Rear node
      Rear = P; // Rear moves up
      Rear -> Next = NULL;
      Count--;
    }
} // comment the 3 cases



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next;
  temp = Front;
  for (int K = 1; K <= J - 1; K++)
    { temp = temp -> Next; }
}

//PURPOSE: will delete the Ith node (I starts out at 1). Count is updated. If I is an illegal value (i.e. > Count or < 1) throw an exception. This should simply call deleteFront ( I = 1) or deleteRear (I == Count) for some cases.
//PARAMETER: I is the position of the node to be deleted. Give back the Ith node element through OldNum (pass by reference).
void llist::deleteIth(int I, el_t& OldNum) 
{ if (I > Count || I < 1) 
    { throw OutOfRange(); } // error case
  else if (I == 1) // special case
    { deleteFront(OldNum); }
  else if (I == Count) // special case
    { deleteRear(OldNum); }
  else // regular case
    { Node* P;
      Node* Q;
      moveTo(I - 1, P);
      moveTo(I + 1, Q);
      OldNum = P -> Next -> Elem;
      delete P -> Next;
      P -> Next = Q;
      Count--;
    }
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: will add right before the Ith node. Count is updated. If I is an Illegal value (i.e. > Count + 1 or < 1) throw an exception. This should simply call addFront (I == 1) or addRear (I == Count + 1) for some cases.
//PARAMETER: I is the position of the node to be inserted. Give back the Ith node element through NewNum (pass by reference).
void llist::insertIth(int I, el_t newNum) 
{ if (I > Count + 1 || I < 1) 
    { throw OutOfRange(); } // error case
  else if (I == 1) // special case
    { addFront(newNum); }
  else if (I == Count + 1) // special case
    { addRear(newNum); }
  else // regular case
    { Node* P;
      Node* Q;
      moveTo(I - 1, P);
      moveTo(I, Q);
      Node* temp = new Node;
      temp -> Elem = newNum;
      P -> Next = temp;
      temp -> Next = Q;
      Count++;
    }
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: Allow passing of a list by value and returning of a list by value.
//PARAMETER: Original is being passed to the constructor by reference to create a new object this-> as a copy of the Original.
llist::llist(const llist& Original) 
{ // this->'s data members need to be initialized here first
  this -> Front = NULL; this -> Rear = NULL; this -> Count = 0;
  // this-> objext has to be built by allocating new cells and copying the values from Original into each cell as we did with operator=. To do this, copy here the (**) lines in Operator Overloading of + but note that it is Original and not OtherOne.
  el_t x;
  // first make sure this-> and Original are not the same object
  // To do this, compare pointers to the objects.
  if (&Original != this) // if not the same
    { // this-> object has to be emptied first
      while (!this -> isEmpty())
	this -> deleteRear(x);
      // this-> object has to be built up by allocating new cells with Original elements (**)
      Node* P; // local pointer for Original
      P = Original.Front;
      while (P != NULL) // a loop which repeats until you reach the end of Original
	{ this -> addRear(P -> Elem); // P's element is added to this->
	  P = P -> Next; // go to the next node in Original
	}
    } // end of if
  // Nothing to return because this is a constructor
} // use my code

//PURPOSE: Allow L1 = L2 in the client: (a regular = cannot copy pointers
//PARAMETER: this-> pointer represents L1 and OtherOne represents L2
llist& llist::operator=(const llist& OtherOne) 
{ el_t x;
  // first make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects.
  if (&OtherOne != this) // if not the same
    { // this-> object has to be emptied first.
      while (!this -> isEmpty())
	this -> deleteRear(x);
      //this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;
      P = OtherOne.Front;
      while (P != NULL) // a loop which repeats until you reach the end of OtherOne.
	{ this -> addRear(P -> Elem); // P's element is added to this->
	  P = P -> Next; // Go to the next node in OtherOne
	}
    } // end of if
  return *this; // return the result unconditionally. Note that the result is returned by reference
} // use my code

