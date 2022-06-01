using namespace std;
#include <iostream>
#include <math.h> //to use floor function
// CS311 YOSHII FALL21
// The Algorithm is in Notes-4A so copy and paste it here!!!!!
// On Empress, control-rightclick will bring up the paste option.
// NEVER delete my comments!!!
//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Carter Rath
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
// This recursive function returns the slot number in which x was found
// or -1
int binarySearch(int L[], int x, int first, int last) 
{
  //  Be sure to check for first > last and
  //   first == last cases to
  //   end the recursion 
  if (first > last) return -1; //exit case, x is not found
  int middle = floor((first + last)/2);
  // as soon as the mid is found... 
  cout << "comparing against an element in slot " << middle << endl;
  // The rest based on the notes
  if (x == L[middle]) return middle; //found x at middle
  else if (x < L[middle]) last = middle - 1; //go to first half
  else if (x > L[middle]) first = middle + 1; //go to second half
  return binarySearch(L, x, first, last); //recursive call
}


int main()
{ int A[10];
  int e;  // to look for this

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, 0, 9);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

}
