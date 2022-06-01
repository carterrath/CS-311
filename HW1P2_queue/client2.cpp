//CS311 Yoshii FALL21
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
// NEVER delete my comments!!!!
//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Carter Rath
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: given a set of characters, generate all possible strings consisting of these characters.
//Algorithm: while loop with exception handling. Loop: remove a string and dislay, add string + "A", add string + "B", and add string + "C". 
int main()
{ queue abc;
  abc.add("A");
  abc.add("B");
  abc.add("C");
  //  place "A", "B", "C" in the queue
  string displaystr;
  while(!abc.isFull()) //  while loop -- indefinitely while(true)
    {
      try
	{   // do the steps noted in the notes 
	  abc.remove(displaystr);
	  cout << displaystr << endl;
	  abc.add(displaystr + "A");
	  abc.add(displaystr + "B");
	  abc.add(displaystr + "C");
	}
      catch (queue::Overflow)
	{ cerr << "Error has occurred - Type is: Overflow, cannot add. "; exit(1); }
      catch (queue::Underflow)
	{ cerr << "Error has occurred - Type is: Underflow, cannot remove. "; exit(1); }
    }// end of loop

}

