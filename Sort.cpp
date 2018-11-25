#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //vector swap
using namespace std;
#include "Sort.h"

template <class dataType> void Sort<dataType>::InsertionSort(vector<dataType>& playList){
  int i;
  int j;
  dataType temp;      // Temporary variable for swap
  
  for (i = 1; i < playList.size(); ++i) {
	  j = i;
	  // Insert numbers[i] into sorted part
	  // stopping once numbers[i] in correct position
    
    while (j > 0 && (playList.at(j).getURating() > playList.at(j-1).getURating())) { //sorted in descendiing order
      //Swap
	  
      temp = playList.at(j);
      playList.at(j) = playList.at(j-1);
      playList.at(j-1) = temp;
      --j;
	  
	  //vector swap
	  //iter_swap(playList.begin() + j, playList.begin() + j - 1);
	  //--j;
    }
  }
  return;
}
