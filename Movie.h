#ifndef MOVIE_H
#define MOVIE_H

class Movie : public Video {
   public:
      Movie();//default constructor
      Movie(string, string);//non-default constructor
      void PrintVideo();
      void GetHS(string);
      string SetHS();
	  void SetMovie();
	  int GetNumber();
	  Movie GetMovies(int, int);
   private: //private variables
      string hassequel;
	  int number;
	  vector <Movie> Movies;
};

#endif