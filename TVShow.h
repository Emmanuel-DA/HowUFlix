#ifndef TVSHOW_H
#define TVSHOW_H

class TVShow : public Video {
   public:
      TVShow();//default constructor
      TVShow(string, string);//non-default constructor
      void PrintVideo();
      void SetSeasons(string seasons);
      void SetEpisodes(string episodes);
      string SetSeasons();
      string SetEpisodes();
   private: //private variables
      string seasons;
      string episodes;
};

#endif