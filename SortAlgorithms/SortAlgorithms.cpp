#include <cstddef>
#include <algorithm>
template<class T>
void SelectionSort(T *pArray, const std::size_t n){ 
  for(std::size_t i=0; i<n; i++){
    auto minOfAll = *(pArray+i); 
    auto swapIndex = i;
    for(std::size_t j=1; j<n; j++){
      if (*(pArray+j) < minOfAll){
	swapIndex = j;
      }
    }
    std::swap(*(pArray+i), *(pArray+swapIndex));
  }
}
