#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>
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
  int time;
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
      EntryS.setInfo(Title, "TV-Show", Genre, Rating, UserRating, stoi(Duration), year);
      EntryS.SetShow();
    }
    else {
      EntryM.setInfo(Title, "Movie", Genre, Rating, UserRating, stoi(Duration), year);
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
  /*
  User1.PrintUserInfo();
  //get shows with first filter

  //TODO: filter#1 and filter #2,3
  
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