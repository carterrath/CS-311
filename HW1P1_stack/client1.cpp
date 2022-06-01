//CS311 Yoshii FALL21
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 
// NEVER delete my comments !!!
//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Carter Rath
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: to perform a user-inputted postfix expression 
//Algorithm: exception handling and a switch inside a loop
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0') // til the end of the expression
    {
      try
       {
	 item = expression[i];  // current char
	 
	 // ** do all the steps in the algorithm given in Notes-2A
	 if(item > 47 && item < 58)
	   {
	     int x = int(item)-48;
	     postfixstack.push(x);
	     postfixstack.displayAll();
	   }
	 else if((item == '*')||(item == '+')||(item == '-'))
	   {
	     int var1, var2;
	     postfixstack.pop(var2);
	     postfixstack.pop(var1);
	     switch(item)
	       {
	         case '*': postfixstack.push(var1 * var2); break;
	         case '+': postfixstack.push(var1 + var2); break;
		 case '-': postfixstack.push(var1 - var2); break;
	       }
	   }
	 else
	   { throw "Invalid element"; }
       } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{ cerr << "Error has occurred - Type is: Overflow, the expression is too long."; exit(1); }
      catch (stack::Underflow)
	{ cerr << "Error has occurred - Type is: Underflow, too few operands."; exit(1); }
      catch (char const* errormsg ) // for invalid item case
	{ cerr << "Error has occured - Type is " << errormsg; exit(1); exit(1); }

      // go back to the loop after incrementing i
      i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
 int result;
 postfixstack.pop(result);
 cout << "The result is:\n" << result << endl;
      
 // If anything is left on the stack, an incomplete expression 
 // was found so also inform the user.
 if(!postfixstack.isEmpty())
   { cout << "Incomplete expression found." << endl; }
}// end of the program
