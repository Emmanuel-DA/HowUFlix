#include <iostream>
#include <string>
using namespace std;
#include "Video.h"

Video::Video() {//constructor
  //initializing
  VideoName = "None";
  VideoType = "None";
  Genre = "None";
  Rating = 0;
  year = "none";

  Duration = 0;
}
Video::Video(string Name, string Type) {//contructor
  VideoName = Name;
  VideoType = Type;
}
void Video::setInfo(string Name, string Type, string Genre, int Rating, string uRating, int Duration, string year){ //mutator
  VideoName = Name;
  VideoType = Type;
  this->Genre = Genre;
  this->Rating = Rating;
  UserRating = uRating;
  this->Duration = Duration;
  this->year = year;
}
void Video::setPlaylistName(string UPlaylist) { //mutator
  Playlist = UPlaylist;
}
string Video::getType() const { //accessor
  return VideoType;
}
string Video::getName() const{ //accessor
  return VideoName;
}
string Video::getPlaylistName() const{ //accessor
  return Playlist;
}
string Video::getDuration() const{ //accessor
  string Duration;
  if (Time.hours != 0)
    Duration = to_string(Time.hours) + " hour ";
  if (Time.minutes != 0)
    Duration += to_string(Time.minutes) + " minutes";
  if (Time.seconds != 0)
    Duration += to_string(Time.seconds) + " seconds ";
  return Duration;
}
string Video::getGenre() const { //accessor
  return Genre;
}

float Video::getRating() const
{
	return Rating;
}
