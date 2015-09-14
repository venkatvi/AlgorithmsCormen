#include <cstddef>
#include <algorithm>
#include <iostream>
using namespace std;
template<class T>
void SelectionSort(T *pArray, const std::size_t n){ 
  for(std::size_t i=0; i<n; i++){
    auto minOfAll = *(pArray+i); 
    auto swapIndex = i;

    for(std::size_t j=i+1; j<n; j++){
      if (*(pArray+j) <= minOfAll){
	minOfAll = *(pArray+j);
	swapIndex = j;
      }
    }
    //    std::swap(*(pArray+i), *(pArray+swapIndex));
    auto tmp = *(pArray+swapIndex);
    *(pArray+swapIndex) = *(pArray+i);
    *(pArray+i) = tmp;
  }
}
