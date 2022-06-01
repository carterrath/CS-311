// CS311 Yoshii FALL21 Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Carter Rath
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{// cout << "slist constructor: "  << endl;
}


// positions always start at 1
// PURPOSE: search through the list to see if any node contains the key. If so, return its position (>=1). Otherwise, return 0.
// PARAMETER: The element that the function needs to find in the list.
int slist::search(el_t key)
{ Node* P = this -> Front;
  for (int i = 1; P != NULL; i++)
    { if (P -> Elem == key) return i; // position found
      P = P -> Next;
    }
  return 0; // position not found
}
el_t slist::search2(el_t X)
{ Node* P = this ->Front;
  el_t blank;
  for(int i = 1; P != NULL; i++)
    { if (P -> Elem == X) return P->Elem; 
      P = P -> Next;
    }
  return blank;
}
// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
// PURPOSE: Throw OutOfRange for bad pos. Use moveTo to go to the pos. Go to the Ith node if I is between 1 and Count and replace the element with the new element.
// PARAMETER: The element to replace the existing element and the position of the node pointing to the existing element
void slist::replace(el_t element, int pos)
{ Node* P;
  if (pos >= 1 && pos <= Count) // position within range
    { moveTo(pos, P);
      P -> Elem = element;
    }
  else throw OutOfRange(); // position not within range, throw exception
}

// PURPOSE: Allow L1 == L2 in the client: A regular == cannot compare two linked lists
// PARAMETER: this-> pointer represents L1 and OtherOne represents L2
bool slist::operator==(const slist& OtherOne)
{ Node* P = OtherOne.Front;
  Node* Q = this -> Front;
  // if not the same length, return false immediately
  if (this -> Count != OtherOne.Count) return false;
  // if the same lengths, check each node to see if the elements are the same
  else
    { while (P != NULL)
	{ if (P -> Elem != Q -> Elem) return false;  // elements not equal 
	  P = P -> Next; Q = Q -> Next;
	}
      return true; // lists are the same
    }
}
