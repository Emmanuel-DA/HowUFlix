#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
#include "Video.h"
#include "Movie.h"

Movie::Movie() {//constructor
  //initializing //using video's
	number = 0;
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
void Movie::SetMovie()
{
	Movies.push_back(*this);
	number++;
}

int Movie::GetNumber()
{
	return number;
}

vector <Movie> Movie::GetMovies(int hours)
{
	vector <Movie> FilteredMovies;
	for (int i = 0; i < number; i++) {
		if (Movies.at(i).Duration < hours) {
			FilteredMovies.push_back(Movies.at(i));
		}
	}
	return FilteredMovies;
}

void Movie::PrintVideo() { //print Video for Movie
	cout << "Video name: " << VideoName << endl;
	cout << "Genre: " << Genre << endl;
	cout << "Rating: " << Rating << endl;
	cout << "User Rating: " << UserRating << endl;
	cout << "Runtime: " << Duration << endl;
	cout << "Release Date: " << year << endl << endl;
}
