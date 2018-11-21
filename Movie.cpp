#include <iostream>
#include <iomanip>
using namespace std;
#include "Video.h"
#include "Movie.h"

Movie::Movie() {//constructor
  //initializing //using video's
}
Movie::Movie(string Name, string Type) {//contructor
  VideoName = Name;
  VideoType = Type;
}
void Movie::GetHS(string HS){
  hassequel = HS; //check for sequel
}
string Movie::SetHS() {
  return hassequel;
} 
void Movie::PrintVideo() { //print Video for Movie
  cout << setw(40) << VideoName << setw(8) << Genre;
  cout << setw(8) << Duration << setw(8) << UserRating;
  cout << setw(8) << Rating << setw(8) << year << endl;
}
