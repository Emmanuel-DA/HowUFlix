#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Search.h"

template <class dataType> int Search<dataType>::LinearSearch(vector<dataType> playList, string videoToFind) { //template Search class

  for (int i = 0; i < playList.size(); i++) {
    if (playList[i].getName() == videoToFind) {
      return i;
    }
  }
  return -1; // not found
}
