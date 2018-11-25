#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
#include "Video.h"
#include "TVShow.h"

TVShow::TVShow() {//constructor
  //initializing
	number = 0;
}

TVShow::TVShow(string Name, string Type) {//contructor
  VideoName = Name;
  VideoType = Type;
}

vector <TVShow> TVShow::GetShows(int hours)
{
	vector <TVShow> FilteredShows;
	for (int i = 0; i < number; i++) {
		if (Shows.at(i).Duration < hours) {
			FilteredShows.push_back(Shows.at(i));
		}
	}
	return FilteredShows;
}

void TVShow::SetSeasons(string seasons) { //set/get unique properties of TV
  this->seasons = seasons;
}

void TVShow::SetEpisodes(string episodes) {
  this->episodes = episodes;
}

void TVShow::SetShow()
{
	Shows.push_back(*this);
	number++;
}

string TVShow::GetSeasons() {
  return seasons;
}

string TVShow::GetEpisodes() {
  return episodes;
}

int TVShow::GetNumber()
{
	return number;
}

void TVShow::PrintVideo() {//print Video for TVShow
	cout << "Video name: " << VideoName << endl;
	cout << "Genre: " << Genre << endl;
	cout << "Rating: " << Rating << endl;
	cout << "User Rating: " << UserRating << endl;
	cout << "Runtime: " << Duration << endl;
	cout << "Release Date: " << year << endl << endl;
}