#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
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
  string  Title, Duration, Genre, Rating, UserRating, name, ID, year, name1, Pname;//input variables
  vector <Movie> Movies;//playlist vector
  vector <TVShow> TVShows;
  bool printedNothing = true;

  // cout << "Example Output: " << endl;//get input from users
  // cout << "Enter a Video Title: " << endl; 
  // getline(cin, Title);
  // cout << "Enter the duration in minutes: " << endl; 
  // getline(cin, Duration);
  // cout << "Enter the video genre: " << endl;
  // getline(cin, Genre);
  // cout << "Enter the rating: " << endl;
  // getline(cin, Rating);
  // cout << "Enter streaming service: " << endl;
  // getline(cin, UserRating);
  // cout << endl;
  


  
  
  while (myfile) {
    getline(myfile, Title, ',');
    getline(myfile, Genre, ',');
    getline(myfile, Duration, ',');
    getline(myfile, UserRating, ',');
    getline(myfile, Rating, ',');
    getline(myfile, year);
    position = Title.find("Season");
    if (position != string::npos) { //check rating to determine TV or movie
      TVShow Entry1;
      Entry1.setInfo(Title, "TV-Show", Genre, Rating, UserRating, stoi(Duration), stoi(year));
      TVShows.push_back(Entry1);
    }
    else {
      Movie Entry1;
      Entry1.setInfo(Title, "Movie", Genre, Rating, UserRating, stoi(Duration), stoi(year));
      Movies.push_back(Entry1);
    }
  }

  cout << "Enter your first name: " << endl;
  getline(cin, name); //get user name
  cout << "Enter your last name: " << endl;
  getline(cin, name1);
  cout << "Enter your userID: " << endl;
  getline(cin, ID); //get user ID
  cout << "Enter playlist name: " << endl;
  getline(cin, Pname);
  User User1(name, name1, ID, Pname); //create an instance of the user class
  cout << endl;
  User1.PrintUserInfo();
  for (int i = 0; i < TVShows.size(); i++){ //search TVSHOw
    if (TVShows.at(i).getGenre() == "Comedy") {
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
  if (printedNothing) {
    cout << "There are no comedies on your playlist." << endl;
  }
  return 0;
}