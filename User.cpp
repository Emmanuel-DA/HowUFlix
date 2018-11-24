#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "User.h"

User::User() { //default constructor
  name = "none";
  name1 = "none";
  ID = "none";
}
User::User(string Name, string Name1, string ID) { //non-default constructor
  name = Name;
  name1 = Name1;
  this->ID = ID;
}
void User::PrintUserInfo() const { //accessor
  cout << "Suggestions for ";
  cout <<  name << " ";
  cout << name1 << endl << endl;
 }