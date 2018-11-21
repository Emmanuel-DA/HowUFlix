#include <iostream>
#include <iomanip>
using namespace std;
#include "User.h"

User::User() { //default constructor
  name = "none";
  name1 = "none";
  ID = "none";
}
User::User(string Name, string Name1, string ID, string Pname) { //non-default constructor
  name = Name;
  name1 = Name1;
  this->ID = ID;
  this->Pname = Pname;
}
void User::PrintUserInfo() const { //accessor
  cout << "User Information: " << endl;
  cout << "Firstname: " << name << endl;
  cout << "Last name: " << name << endl;
  cout << "userid: " << ID << endl;
  cout << "Playlist name: " << Pname << endl << endl;
  cout << "________________________________________________________________________________________" << endl;
  cout << left << setw(40) << "Title" << "Genre" << "  ";
  cout << "Duration" << "  " << "User-rating" << "  "; 
  cout << "Rating" << "  " << "Year" << "  " << endl;  
 }