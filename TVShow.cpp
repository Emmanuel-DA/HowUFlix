#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
#include "Video.h"
#include "TVShow.h"

TVShow::TVShow() {//constructor
  //initializing
}

TVShow::TVShow(string Name, string Type) {//contructor
  VideoName = Name;
  VideoType = Type;
}

TVShow TVShow::GetShows(int hours, int number)
{
	if (Shows.at(number).Duration < hours) {
		return Shows.at(number);
	}
	//try except from the main function will be used to handle this exception
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
  cout << left << setw(40) << VideoName << Genre << "     ";
  cout << setw(8) << Duration << setw(8) << UserRating;
  cout << setw(8) << Rating << setw(8) << year << endl;
}