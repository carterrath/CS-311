// CS311 Yoshii FALL21 - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//  NEVER delete my comments!!
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Carter Rath
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{ return key % TSIZE; }

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.getkey());  // hash with the key part
  // Note that this means adding the element to a slist in the slot (call addRear)
  table[slot].addRear(element);
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey); // initialize selement with just the skey (call setkey)
 el_t found = table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return found; // return the found element from here (it could be blank)
}

// finds the element given the key  and deletes it from the table.
//  Returns the slot number.
int htable:: deleteIt(int skey)
{
  int slot = hash(skey); // hash with skey
  el_t selement;  // this is the element to look for in slist
  selement.setkey(skey); //  initialize selement with just the skey
  int I = table[slot].search(selement); //  call slist's search which gives you the location I and then deleteIth
  table[slot].deleteIth(I, selement);
  return slot; //  return the slot number
}

// fills the table using the specified input file 
void htable::fillTable(istream& fin)
{
  //  model this after HW6 to get data from the file the user specified
  //  which elem and slist functions do you call? List them here first.
  int akey, slot;
  string aname, atype, acolor;
  while(fin >> akey)
    {
      fin >> aname;
      fin >> atype;
      fin >> acolor;
      el_t anelement(akey, aname, atype, acolor);
      slot = hash(akey);
      table[slot].addRear(anelement);
    }
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)
    { cout << i << ":" ;   
      table[i].displayAll(); // call slist's displayAll
    }
}

// saves into the specified file in the same format as the input file
void htable::saveTable(ostream& fout) 
{
  el_t x;
  slist a;
  for(int i = 0; i < TSIZE; i++)
    {
      a = table[i];
      if(a.isEmpty())
	{
	  //do nothing
	}
      else
	{
	  while(!a.isEmpty())
	    {
	      a.deleteFront(x);
	      fout << x << endl;
	    }
	}
    }
}
