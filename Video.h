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
      void setInfo(string, string, string, float, string, int, string);//mutator
      void setPlaylistName(string);
      string getType() const;//accessor
      string getName() const;//accessor
      string getPlaylistName() const;//accessor
      string getDuration() const;//accessor
      string getGenre() const; //accessor
	  float getURating() const; //accessor
      virtual void PrintVideo() = 0;
	  void sneakpeak();//preview of video
    private: //private variables
      string Playlist;
    protected: //protected variables//accessible by base and derived
      string VideoName;
      string VideoType;
      string Genre;
      float UserRating;
      string Rating;
      string year;
      timeinfo Time;
      int Duration;
};

#endif