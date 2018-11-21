#include <iostream>
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
void TVShow::SetSeasons(string seasons) { //set/get unique properties of TV
  this->seasons = seasons;
}
void TVShow::SetEpisodes(string episodes) {
  this->episodes = episodes;
}
string TVShow::SetSeasons() {
  return seasons;
}
string TVShow::SetEpisodes() {
  return episodes;
}
void TVShow::PrintVideo() {//print Video for TVShow
  cout << left << setw(40) << VideoName << Genre << "     ";
  cout << setw(8) << Duration << setw(8) << UserRating;
  cout << setw(8) << Rating << setw(8) << year << endl;
}