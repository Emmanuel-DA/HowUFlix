#include <iostream>
#include <vector>
using namespace std;
#include "Sort.h"

template <class dataType> void Sort<dataType>::InsertionSort(vector<dataType> playList){
  int i;
  int j;
  dataType temp;      // Temporary variable for swap
  
  for (i = 1; i < playList.size(); ++i) {
    j = i;
    // Insert numbers[i] into sorted part
    // stopping once numbers[i] in correct position
    
    while (j > 0 && playList.at(j) < playList.at(j-1)) {
      //Swap
      temp = playList.at(j);
      playList.at(j) = playList.at(j-1);
      playList.at(j-1) = temp;
      --j;
    }
  }

  for (int i = 0; i < playList.size(); i++){
    cout << playList.at(i) << " ";
  }
  cout << endl;
  return;
}
