#ifndef TVSHOW_H
#define TVSHOW_H

class TVShow : public Video {
   public:
      TVShow();//default constructor
      TVShow(string, string);//non-default constructor
	  vector <TVShow> GetShows(int);
      void PrintVideo();
      void SetSeasons(string seasons);
      void SetEpisodes(string episodes);
	  void SetShow();
      string GetSeasons();
      string GetEpisodes();
	  int GetNumber();
   private: //private variables
      string seasons;
      string episodes;
	  int number;
	  vector <TVShow> Shows;
};

#endif