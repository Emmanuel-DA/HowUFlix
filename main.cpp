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
#include "Sort.h"
#include "Search.h"
#include "Sort.cpp"
#include "Search.cpp"

int main() {
  size_t position;
  ifstream myfile;
  myfile.open("FavoriteMovieTVShowsClassList.csv");
  string  Title, Duration, Genre, Rating, UserRating, name, ID, year, name1, Pname, Utime, Urating, Ugenre, video;//input variables
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
  cout << "How much me time have you set aside (minutes) :) --> ";
  getline(cin, Utime); //get time
  cout << "How good should the video be (Scale of 1 - 5) --> ";
  getline(cin, Urating);
  cout << "What genre do you want to watch (Seperate multiple genres with a space) --> ";
  getline(cin, Ugenre); //get user ID
  cout << endl;
  time = stoi(Utime); //look for exceptions
  rating = stoi(Urating);


  //TVShows
  vector <TVShow> TVShowsFilter0; //containing required TV shows-- rating filter
  vector <TVShow> TVShowsFilter; //containing required TV shows-- genre filter
  //first filter-time
  TVShows = EntryS.GetShows(time); 
  //second filter-rating
  for (int i = 0; i < TVShows.size(); i++) {//check for a range of ratings so you can suggest to the user
	  if (abs((TVShows.at(i).getURating()) - rating) < 0.5) { //
		  TVShowsFilter0.push_back(TVShows.at(i));
	  }
  }
  //Last filtering - genre
  vector <string> UG; //store user genre
  char letter;
  string genre;
  for (int i = 0; i < Ugenre.size(); i++) {//seperate the genre into the a genre vector
	  if (Ugenre[i] == ' ') { //space delimeter
		  UG.push_back(genre);
		  genre = "";
		  i++;
	  }
	  genre += Ugenre[i];
	  if (i == (Ugenre.size() - 1)) { //end of line delimeter
		  UG.push_back(genre);
	  }
  }
  for (int i = 0; i < TVShowsFilter0.size(); i++) {//check for a range of ratings so you can suggest to the user
	  for (int j = 0; j < UG.size(); j++) {
		  position = TVShowsFilter0.at(i).getGenre().find(UG.at(j));
		  if (position != string::npos) {
			  TVShowsFilter.push_back(TVShowsFilter0.at(i));
		  }
	  }
  }
  //------------------------------------------------------End TVShows

  
  //Movies
  vector <Movie> MoviesFilter0; //containing required TV shows -- rating filter
  vector <Movie> MoviesFilter; //containing required TV shows -- genre filter
  //first filter-time
  Movies = EntryM.GetMovies(time);
  //second filter-rating
  for (int i = 0; i < Movies.size(); i++) {//check for a range of ratings so you can suggest to the user
	  if (abs((Movies.at(i).getURating()) - rating) < 0.5) { //
		  MoviesFilter0.push_back(Movies.at(i));
	  }
  }
  //Last filtering - genre
  for (int i = 0; i < MoviesFilter0.size(); i++) {//check for a range of ratings so you can suggest to the user
	  for (int j = 0; j < UG.size(); j++) {
		  position = MoviesFilter0.at(i).getGenre().find(UG.at(j));
		  if (position != string::npos) {
			  MoviesFilter.push_back(MoviesFilter0.at(i));
		  }
	  }
  }
//-----------------------------------------------End Movies
  
  User1.PrintUserInfo();//user details

  Sort<TVShow>::InsertionSort(TVShowsFilter);//sort according to rating using static function
  Sort<Movie>::InsertionSort(MoviesFilter);
  cout << "TVShows ---------------------" << endl;//show suggestion to user
  for (int i = 0; i < TVShowsFilter.size(); i++) {
	  TVShowsFilter.at(i).sneakpeak();
	  cout << endl;
	  printedNothing = false;
  }
  cout << endl;
  cout << "Movies ---------------------" << endl;
  for (int i = 0; i < MoviesFilter.size(); i++) {
	  MoviesFilter.at(i).sneakpeak();
	  cout << endl;
	  printedNothing = false;
  }
  cout << endl;
  if (!printedNothing) {
	  cout << "What video would you like to watch (Enter title from above) ---> ";
	  getline(cin, video);
	  cout << endl;

	  int index; //look for the index from the suggested one
	  bool isMovie = true;
	  index = Search<Movie>::LinearSearch(MoviesFilter, video);
	  if (index == NULL) {
		  index = Search<TVShow>::LinearSearch(TVShowsFilter, video);
		  isMovie = false;
	  }
	  if (isMovie) { //print 
		  MoviesFilter.at(index).PrintVideo();
	  }
	  else {
		  TVShowsFilter.at(index).PrintVideo();
	  }
  }
  else {
    cout << "We are sorry none of your input was able to result in a suggestion but we will keep improving our database" << endl;
  }
  cout << "Thank you for using HowUFlix" << endl << endl;
  system("pause");
  return 0;
}
