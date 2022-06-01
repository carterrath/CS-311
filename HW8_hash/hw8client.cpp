// CS311 Yoshii FALL21 - ** should be completed!!!
//
// Note that the client knows about elem.h functions.
// It can create el_t objects.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+other info to add to the table. e.g. el_t X(30, "mary"...);
// NEVER delete my comments!!
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Carter Rath
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"
#include <iostream>
#include <fstream>
#include <string>

//** Add an explanation of what this App should be used for. 
int main()
{ 
  cout << "This App takes a list of clothing items, and fills them into a hash table with a size of 37. These clothing items are identified by 4 different parts of information: key, name, type, and color." << endl; // cout an explanation of what this App should be used for. 

  htable HT;
  string fname; // file name - decided to get the file name here
            // in the client in case the way I get them is application dependent

  cout << "What is the input file? (.txt file) ";
  cin >> fname;
  
  ifstream fin (fname.c_str(), ios::in);
  HT.fillTable(fin);
  // this is the output file - newout.txt
  ofstream fout ("newout.txt", ios::out);  

  //HT.fillTable(fin);

  // make sure some of elements  collide. (Call function add)
  HT.displayTable();
  cout << endl;

  int selection;
  do {

  cout << "MENU: ---- " << endl; 
  cout << "1 Add an element" << endl; 
  cout << "2 Find an element" << endl;
  cout << "3 Delete an element" << endl;
  cout << "4 Display the table" << endl;
  cout << "5 Save the table to a file" << endl;    
  cout << "6 Quit" << endl;
  cin >> selection;

      int thekey;
      string thename, thetype, thecolor;
      el_t theelement;
      int s;

    switch (selection) {

    case 1:  // Add and indicate slot
      cout << "What is the key to add? ";
      cin >> thekey;
      cout << "What is the name of the clothing item? " ;
      cin >> thename;
      //  Here get two more pieces of info
      cout << "What is the type of the clothing item? ";
      cin >> thetype;
      cout << "What is the color of the clothing item? ";
      cin >> thecolor;
      theelement = el_t(thekey, thename, thetype, thecolor);  //  Create the element with all the info 
      s = HT.add(theelement);
      cout << "Added the element in slot " << s << endl;
      break;

    case 2: // Find and indicate element
      cout << "What is the key to find? ";
      cin >> thekey;
      theelement =  HT.find(thekey); // find based on thekey
      cout << "Found this:" << endl;
      cout << theelement << endl;
      break;      

    case 3: // Delete and indicate slot
      cout << "What is the key to find? ";
      cin >> thekey;
      s  =  HT.deleteIt(thekey); // find and delete it based on thekey
      if (s == -1) cout << "Not found!" << endl; else
      cout << "Found it and deleted it from slot:" << s << endl;
      break;      

    case 4: // Display
      cout << "The current contents are: " << endl;
      HT.displayTable();
      break;

    case 5: // Save in the same format as input file
      HT.saveTable(fout);
      cout << "Saved the updated table in newout.txt" << endl;
      break;

    default:
      cout << "bye" << endl;
    }
  }
  while (selection != 6);
  fin.close();
  fout.close();
 }
