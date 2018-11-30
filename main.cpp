/*
                  *********************************************
                  *********************************************
                  *********                           *********                           
                  *********        ALGORITHM          *********
                  *********        HOWUFLIX!          *********
                  *********                           *********
                  *********************************************
                  *********************************************
                  
1: Populate our database by reading information from the file
2: Filter the videos into movies and TV shows based on keyword - "Season". At the end of this step, we have one vector containing all movies from the file and another containing all TV shows. 
3: We obtain user information and store this in a user class object.
4: We obtain user input indicating their video preferences, specifically the amount of free time they have, their desired rating and preferred genres. 
5: Based on the information we get, videos are suggested that are filtered in 3 stages:
  a.) have durations similar to or less than the amount of free time the user has 
  b.) have ratings similar to the user's desired rating (with a tolerance range of 0.5) 
  c.) are of the desired genre
6: The shortlist generated from suggested output is displayed to the user, narrowing down the options they have to choose between. 
7: The user makes a choice from the list presented and proceeds to watch the desired video.

The exceptions handle for negative time input, a rating outside the range of 1-5 and a genre that's outside the selection available in the database. There's also exception handling code for incorrectly typed video titles. Incorrect letter capitalization in names and titles has adequately been accounted for by capitalizing the first letter of each word in a title or name. 

Searching for videos within the database is implemented using the Linear Search algorithm, sorting available videos is done using Selection Sort algorithm.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;
#include "Video.h"
#include "TVShow.h"
#include "Movie.h"
#include "User.h"
#include "Sort.h"
#include "Search.h"
#include "Sort.cpp"
#include "Search.cpp"

string capitalize(string);

int main() {
  size_t position;
  ifstream myfile;
  myfile.open("FavoriteMovieTVShowsClassList.csv"); //open file
  string  Title, Duration, Genre, Rating, UserRating, firstname, ID, year, lastname, Utime, Urating, Ugenre, video;//input variables
  int time, rating;
  TVShow EntryS; //class instances for database
  Movie EntryM;

  vector <Movie> Movies;//containing required movies -- (filtered with movies)
  vector <TVShow> TVShows; //containing required TV shows -- (filtered with time)
  vector <Movie> MoviesFilter0; //containing required movies -- (filtered with ratings)
  vector <TVShow> TVShowsFilter0; //containing required TV shows-- (filtered with with ratings)
  vector <Movie> MoviesFilter; //containing required movies shows -- (filtered with genre)
  vector <TVShow> TVShowsFilter; //containing required TV shows-- (filtered with genre)
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
      EntryS.setInfo(capitalize(Title), "TV-Show", Genre, stof(UserRating), Rating, stoi(Duration), year);
      EntryS.SetShow();
    }
    else {
      EntryM.setInfo(capitalize(Title), "Movie", Genre, stof(UserRating), Rating, stoi(Duration), year);
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
  getline(cin, firstname); //get user name
  firstname = capitalize(firstname);
  cout << "Last name: ";
  getline(cin, lastname);
  lastname = capitalize(lastname);
  cout << "userID: ";
  getline(cin, ID); //get user ID
  User User1(firstname, lastname, ID); //create an instance of the user class
  cout << endl;

  cout << "For maximum satisfaction please enlarge the size of your console" << endl << endl;
  
  //-----------------------------------------------------------------Get time from user
  try { 
	  bool error = true;
	cout << "How much me time have you set aside (minutes) :) --> ";
	while (error) {   //------------------Handling exceptions
		getline(cin, Utime); //get time
		try {
			time = stoi(Utime); //kept to have a variety of responses
			/*
			if (time < 0) {
				throw runtime_error("Invalid time");
			}
			*/
			for_each(Utime.begin(), Utime.end(), [](char & character) { //accurately replaces previous checks
				if (!::isdigit(character)) { //if input contains lurking non-integers
					throw runtime_error("Invalid time");
				}
			});
			error = false;
		}
		catch (runtime_error& excpt) {
			cout << "Please enter a number greater than zero: ";
		}
		catch (...) {
			cout << "Please enter only numbers: ";
		}
	}

	//-----------------------------------------------------------------Get rating from user
	cout << "How good should the video be (Scale of 1 - 5) --> ";
	error = true;
	while (error) {   //------------------Handling exceptions
		getline(cin, Urating); //get rating
		try {
			rating = stoi(Urating);
			if (rating < 0 || rating > 5) {
				throw runtime_error("Invalid rating.");
			}
			for_each(Urating.begin(), Urating.end(), [](char & character) { //
				if (!::isdigit(character)) { //if input contains lurking non-integers
					throw runtime_error("Invalid time");
				}
			});
			error = false;
		}
		catch (runtime_error& excpt) {
			cout << "Please enter a number between 0 and 5 inclusive: ";
		}
		catch (...) {
			cout << "Please enter only numbers: ";
		}
	}

	//-----------------------------------------------------------------Get genre from user
    cout << "What genre do you want to watch (Seperate multiple genres with a space)" << endl;
	cout << "(Leave blank and hit enter to include all available genres) --> ";
    getline(cin, Ugenre); //get user ID
	Ugenre = capitalize(Ugenre);
    cout << endl;

    //TVShows
    
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
	if (UG.size() == 0) { //additional "search for all genres" feature
		UG.push_back("Drama");
		UG.push_back("Action");
		UG.push_back("Animation");
		UG.push_back("Science");
		UG.push_back("Fiction");
		UG.push_back("Teen");
		UG.push_back("Romance");
		UG.push_back("Mystery");
		UG.push_back("Thriller");
		UG.push_back("Horror");
	}
    for (int j = 0; j < UG.size(); j++) {//check for genre
      for (int i = 0; i < TVShowsFilter0.size(); i++) {
        position = TVShowsFilter0.at(i).getGenre().find(UG.at(j));
        if (position != string::npos) {
          TVShowsFilter.push_back(TVShowsFilter0.at(i));
		  TVShowsFilter0.erase(TVShowsFilter0.begin() + i); //remove the already added show to avoid duplication
        }
      }
    }
    //------------------------------------------------------End TVShows

    
    //Movies

    //first filter-time
    Movies = EntryM.GetMovies(time);
    //second filter-rating
    for (int i = 0; i < Movies.size(); i++) {//check for a range of ratings so you can suggest to the user
      if (abs((Movies.at(i).getURating()) - rating) < 0.5) { //
        MoviesFilter0.push_back(Movies.at(i));
      }
    }
    //Last filtering - genre
    for (int j = 0; j < UG.size(); j++) {//check for genre
      for (int i = 0; i < MoviesFilter0.size(); i++) {
        position = MoviesFilter0.at(i).getGenre().find(UG.at(j));
        if (position != string::npos) {
          MoviesFilter.push_back(MoviesFilter0.at(i));
		  MoviesFilter0.erase(MoviesFilter0.begin() + i); //remove the already added movie to avoid duplication
        }
      }
    }
  //-----------------------------------------------End Movies
    
    User1.PrintUserInfo();//user details

    Sort<TVShow>::InsertionSort(TVShowsFilter);//sort according to rating using static function
    Sort<Movie>::InsertionSort(MoviesFilter);
    cout << "TVShows --------------------------------------------------------------------------------------" << endl << endl;//show suggestion to user
    for (int i = 0; i < TVShowsFilter.size(); i++) {
      TVShowsFilter.at(i).sneakpeak();
      cout << endl;
      printedNothing = false;
    }
    cout << endl;
    cout << "Movies ---------------------------------------------------------------------------------------" << endl << endl;
    for (int i = 0; i < MoviesFilter.size(); i++) {
      MoviesFilter.at(i).sneakpeak();
      cout << endl;
      printedNothing = false;
    }
    cout << endl;
    if (!printedNothing) {
		error = true;
		int index; //look for the index from the suggested one
		bool isMovie = true; //check if the user is picking a show or movie
		cout << "What video would you like to watch (Enter title from above) ---> ";
		while (error) {   //------------------Handling exceptions
			getline(cin, video); //get video
			video = capitalize(video);
			try {
				index = Search<Movie>::LinearSearch(MoviesFilter, video);
				if (index == -1) {
					index = Search<TVShow>::LinearSearch(TVShowsFilter, video);
					isMovie = false;
				}
				if (index == -1) {
					isMovie = true; //reset to initial condition
					throw - 1;
				}
				error = false;
			}
			catch (...) {
				cout << "Please make sure you match the title given in the sneak peek: ";
			}
		}
	  cout << endl;
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
      
    }
  catch (...) {
    // Prints the error message passed by throw statement
    //cout << excpt.what() << endl;
	  cout << "Yikes! Something went wrong. Check back in a bit." << endl;
	  cout << "----HowUFlix----" << endl << endl;
  }

  system("pause");
  return 0;
}

string capitalize(string userInput) {
	char last = ' ';
	for (int i = 0; i < userInput.size(); i++) {//seperate the genre into the a genre vector
		if (last == ' ' && userInput[i] != ' ' && ::isalpha(userInput[i])) {
			userInput[i] = ::toupper(userInput[i]);
		}
		last = userInput[i];
	}
	return userInput;
}
		
