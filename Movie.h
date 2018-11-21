#ifndef MOVIE_H
#define MOVIE_H

class Movie : public Video {
   public:
      Movie();//default constructor
      Movie(string, string);//non-default constructor
      void PrintVideo();
      void GetHS(string);
      string SetHS();      
   private: //private variables
      string hassequel;

};

#endif