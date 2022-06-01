//CS311 Yoshii FALL21 dgraph.cpp 
// INSTRUCTION:
//   Complete all the functions you listed in dgraph.h
//   Comment the file completely using How to Comment file.
//   Use HW6-help.docx to finish the functions.
//  NEVER delete my comments!!!
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Carter Rath
// File Type: dgraph.cpp implementation file
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"
#include <iomanip>

dgraph::dgraph()
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
 // initialize countUsed to be 0
{
  for(int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }
  countUsed = 0;
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

void dgraph::fillTable()  // be sure to read from a specified file
// you will have to use a linked list function addRear. 
{
  string fname;
  char x;
  int edges = 0;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
  while(fin >> Gtable[countUsed].vertexName)
    {
      fin >> Gtable[countUsed].outDegree;
      edges += Gtable[countUsed].outDegree;
      for(int i = 0; i < Gtable[countUsed].outDegree; i++) {
	fin >> x;
	(Gtable[countUsed].adjacentOnes).addRear(x);
      }
      countUsed++;
    }
  fin.close();
  cout << "The number of edges is: " << edges << endl;
}
void dgraph::displayGraph() // be sure to display
// you will have to use a linked list function displayAll. 
{// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top 
  string dashes(50, '-');
  cout << setw(7) << "Out" << setw(8) << "Visit" << setw(6) << "Adj" << endl;
  cout << dashes << endl;
  for(int i = 0; i < countUsed; i++)
    {
      cout << left << setw(4) << Gtable[i].vertexName;
      cout << setw(6) << Gtable[i].outDegree;
      cout << setw(8) << Gtable[i].visit;
      Gtable[i].adjacentOnes.displayAll();
    }
}

int dgraph::findOutDegree(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
  int index = V - 65;
  if(index >= countUsed || index < 0) { throw BadVertex(); }
  else { return Gtable[index].outDegree; }
}

slist dgraph::findAdjacency(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
  int index = V -65;
  if(index >= countUsed || index < 0) { throw BadVertex(); }
  else { return Gtable[index].adjacentOnes; }
}

void dgraph::visit(int X, char V)
{
  int index = V - 65;
  Gtable[index].visit = X;
}

bool dgraph::isMarked(char V)
{
  int index = V - 65;
  if(Gtable[index].visit == 0)
    { return false; } // vertex not visited
  else
    { return true; } // vertex has not been visited
}
  
