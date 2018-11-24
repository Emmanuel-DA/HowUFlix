#include <iostream>
#include <vector>
using namespace std;
#include "Search.h"

template <class dataType> dataType Search<dataType>::LinearSearch(vector<dataType> playList, dataType videoToFind) {

  for (int i = 0; i < playList.size(); ++i) {
    if (playList[i] == videoToFind) {
      return playList[i];
    }
  }
  return NULL; // not found
}
