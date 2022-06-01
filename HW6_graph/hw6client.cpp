// CS311 Yoshii FALL21
// HW6 Client file 
// INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Carter Rath
// File type:  hw6client.cpp  (tester)
// ================================================

#include <iostream>
using namespace std;
#include "dgraph.h"  // includes

 // comments
int main()
{  
    //0.Declare dgraph object
  dgraph D;
    //1.fillTable()
  D.fillTable();
    //2.displayGraph()
  D.displayGraph();
    //while (the user does not want to stop)
  char exit = 'Y', vertex;  
  while(exit == 'Y' || exit == 'y') {
    //a.the user will specify which vertex
    try {
      cout << "Enter a vertex: ";
      cin >> vertex;
    //b.findOutDegree of the vertex and display the result
      cout << D.findOutDegree(vertex) << " edges comes out to: ";
    //b.findAdjacency of the vertex and display the result (see Hint)
      slist L1;
      L1 = D.findAdjacency(vertex);
      L1.displayAll();
    }
    //c.catch exception to display error mesg but do not exit
    catch(dgraph::BadVertex) {
      cerr << "no such vertex exists"  << endl;
    }
    cout << "Would you like to enter another vertex? (Y/N): ";
    cin >> exit;
  } //end of while
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
