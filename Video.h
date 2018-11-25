#ifndef VIDEO_H
#define VIDEO_H

struct timeinfo {
  int hours;
  int minutes;
  int seconds;
};

class Video {
   public:
      Video();//default constructor
      Video(string, string);//non-default constructor
      void setInfo(string, string, string, int, string, int, string);//mutator
      void setPlaylistName(string);
      string getType() const;//accessor
      string getName() const;//accessor
      string getPlaylistName() const;//accessor
      string getDuration() const;//accessor
      string getGenre() const; //accessor
	  float getRating() const; //accessor
      virtual void PrintVideo() = 0;
    private: //private variables
      string Playlist;
    protected: //protected variables//accessible by base and derived
      string VideoName;
      string VideoType;
      string Genre;
      float Rating;
      string UserRating;
      string year;
      timeinfo Time;
      int Duration;
};

#endif