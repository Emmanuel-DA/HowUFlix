#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>
#include <future> //async
using namespace std;
#include "Video.h"
#include "TVShow.h"
#include "Movie.h"
#include "User.h"

int main() {
  size_t position;
  ifstream myfile;
  myfile.open("FavoriteMovieTVShowsClassList.csv");
  string  Title, Duration, Genre, Rating, UserRating, name, ID, year, name1, Pname, Utime, Urating, Ugenre;//input variables
  int time,rating;
  TVShow EntryS; //class instances
  Movie EntryM;

  vector <Movie> Movies;//playlist vector
  vector <TVShow> TVShows;
  bool printedNothing = true;
  
  while (!myfile.eof()) { //Populate Database
    getline(myfile, Title, ',');
    getline(myfile, Genre, ',');
    getline(myfile, Duration, ',');
    getline(myfile, UserRating, ',');
    getline(myfile, Rating, ',');
    getline(myfile, year);
    position = Title.find("Season");
    if (position != string::npos) { //check rating to determine TV or movie
      EntryS.setInfo(Title, "TV-Show", Genre, stof(UserRating), Rating, stoi(Duration), year);
      EntryS.SetShow();
    }
    else {
      EntryM.setInfo(Title, "Movie", Genre, stof(UserRating), Rating, stoi(Duration), year);
	  EntryM.SetMovie();
    }
  }

  cout << "***------------------------------------------------------------------------------------------***" << endl << endl;//intro
  cout << right << setw(86) << "***Welcome to HowUFlix, an advanced streaming platform from the future.***" << endl << endl;
  cout << "This platform is built with human empathy as the backbone" << endl;
  cout << "With an intuitive approach, users are able to tailor their streaming experiences in a very flexible way." << endl << endl;
  cout << "***------------------------------------------------------------------------------------------***" << endl << endl;

  cout << "We just need some info and you're set to dive in!" << endl << endl;
  cout << "First name: ";
  getline(cin, name); //get user name
  cout << "Last name: ";
  getline(cin, name1);
  cout << "userID: ";
  getline(cin, ID); //get user ID
  User User1(name, name1, ID); //create an instance of the user class
  cout << endl;

  cout << "For maximum satisfaction please enlarge the size of your console" << endl << endl;

  //ask for user input
  cout << "How much me time have you set aside :) --> ";
  getline(cin, Utime); //get time
  cout << "How good should the video be (Scale of 1 - 5) --> ";
  getline(cin, Urating);
  cout << "What genre do you want to watch (Seperate multiple genres with a space) --> ";
  getline(cin, Ugenre); //get user ID
  cout << endl;
  time = stoi(Utime); //look for exceptions
  rating = stoi(Urating);


  //TVShows
  //first filter-time
  for (int i = 0; i < EntryS.GetNumber(); i++) {
	  try {
		  TVShows.push_back(EntryS.GetShows(time, i)); //catch exception when the function returns nothing
	  }
	  catch (...) {
		  ;
	  }
  }
  //second filter-rating
  for (int i = 0; i < TVShows.size(); i++) {//check for a range of ratings so you can suggest to the user
	  if (abs((TVShows.at(i).getRating()) - rating) < 0.2) { //
		  TVShows.erase(TVShows.begin() + i);
	  }
  }
  //Last filtering - genre
  vector <string> UG; //store user genre
  char letter;
  string genre;
  for (int i = 0; i < Ugenre.size(); i++) {//seperate the genre into the a genre vector
	  if (Ugenre[i] == ' ') {
		  UG.push_back(genre);
	  }
	  genre += Ugenre[i];
  }
  for (int i = 0; i < TVShows.size(); i++) {//check for a range of ratings so you can suggest to the user
	  for (int j = 0; j < genre.size(); j++) {
		  position = TVShows.at(i).getGenre().find(genre[j]);
		  if (position == string::npos) {
			  TVShows.erase(TVShows.begin() + i);
		  }
	  }
  }
  //------------------------------------------------------End TVShows

  
  //Movies
  //first filter-time
  for (int i = 0; i < EntryM.GetNumber(); i++) {
	  try {
		  Movies.push_back(EntryM.GetMovies(time, i)); //catch exception when the function returns nothing
	  }
	  catch (...) {
		  ;
	  }
  }
  //second filter-rating
  for (int i = 0; i < Movies.size(); i++) {//check for a range of ratings so you can suggest to the user
	  if (abs((Movies.at(i).getRating()) - rating) < 0.2) { //
		  Movies.erase(Movies.begin() + i);
	  }
  }
  //Last filtering - genre
  vector <string> UG2; //store user genre
  char letter2;
  string genre2;
  for (int i = 0; i < Ugenre.size(); i++) {//seperate the genre into the a genre vector
	  if (Ugenre[i] == ' ') {
		  UG2.push_back(genre);
	  }
	  genre2 += Ugenre[i];
  }
  for (int i = 0; i < Movies.size(); i++) {//check for a range of ratings so you can suggest to the user
	  for (int j = 0; j < genre2.size(); j++) {
		  position = Movies.at(i).getGenre().find(genre2[j]);
		  if (position == string::npos) {
			  Movies.erase(Movies.begin() + i);
		  }
	  }
  }
//-----------------------------------------------End Movies
  
  //TODO: Sort and print to the user and then search
  User1.PrintUserInfo();//user details

  /*
  
  for (int i = 0; i < TVShows.size(); i++){ //search TVSHOw
    if (EntryS.Shows.at(i).getGenre() == "Comedy") {
      TVShows.at(i).PrintVideo();
      printedNothing  = false;
    }
  } 
  for (int i = 0; i < Movies.size(); i++){ //search Movie
    if (Movies.at(i).getGenre() == "Comedy") {
      Movies.at(i).PrintVideo();
      printedNothing = false;
    }
  }
  */
  if (printedNothing) {
    cout << "We are sorry none of your input was able to result in a suggestion but we will keep improving our database" << endl;
  }
  cout << "Thank you for using HowUFlix" << endl << endl;
  system("pause");
  return 0;
}