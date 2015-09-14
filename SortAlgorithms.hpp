#include <cstddef>
#include <algorithm>

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
    std::swap(*(pArray+i), *(pArray+swapIndex));
  }
}

template<class T>
void InsertionSort(T* pArray, const std::size_t n){
  for(std::size_t i=1; i<n; i++){
    auto elementToSort = *(pArray+i);
    auto insertIndex = i;
    for( std::size_t j=i-1; j>=0; j--){
      if (*(pArray+j) < elementToSort){
	insertIndex = j+1;
	break;
      }
    }
    if(insertIndex != i){
      for (std::size_t j=i-1; j>=insertIndex; j--){
	*(pArray+j+1) = *(pArray+j);
      }
      *(pArray+insertIndex) = elementToSort;
    }
  }
}
