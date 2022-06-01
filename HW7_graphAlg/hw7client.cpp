// CS311 YOSHII FALL21

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Carter Rath
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include both dgraph  and stack
#include <iostream>
using namespace std;
#include "dgraph.h"
#include "stack.h"
// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that for the comments. 
  dgraph d;
  stack s;
  char v = ' ';
  int visit = 0;
  slist sl;
  d.fillTable();
  // Display the graph before DFS begins
  d.displayGraph();
  // Push A onto the stack to start
  s.push('A');
  // while the stack is not empty do
  while(!s.isEmpty())
    { // Remove a vertex v from the stack
      s.pop(v);
      // Display the vertex name
      cout << "Removed " << v << " from stack" << endl;
      // if v is not marked yet (visit number is 0) then
      if(!d.isMarked(v))
	{ // mark it and inform the user
	  visit++;
	  d.visit(visit, v);
	  cout << "Visit " << v << " as " << visit << endl;
	  // get its adjacency list (slist)
	  sl = d.findAdjacency(v);
	  // if no adjacent ones inform the user
	  if(d.findOutDegree(v) == 0)
	    { cout << "Deadend reached - backup" << endl; }
	  // else put adjacent ones onto the stack (delete from the rear and push) informing the user
	  else
	    { cout << "...pushing";
	      sl.displayAll();
	      while(!sl.isEmpty())
		{ sl.deleteRear(v);
		  s.push(v);
       
		}
	    } 
	}
      // else informs the user
      else
	{ cout << v << " had been visited already - backup." << endl; }
      // display stack
      s.displayAll();
    }
      // display the graph nicely
  d.displayGraph();
}
