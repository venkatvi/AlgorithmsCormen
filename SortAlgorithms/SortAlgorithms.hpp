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
    std::swap(*(pArray+i), *(pArray+swapIndex));
  }
}

template<class T>
void InsertionSort(T* pArray, const std::size_t n){
  for(std::size_t i=1; i<n; i++){
    auto elementToSort = *(pArray+i);
    auto insertIndex = i;
    
    for( std::size_t j=0; j <i ; j++){
      if (*(pArray+j) > elementToSort){
	insertIndex = j;
	break;
      }
    }
    if(insertIndex != i){
      for (std::size_t j=i; j>insertIndex; j--){
	*(pArray+j) = *(pArray+j-1);
      }
      *(pArray+insertIndex) = elementToSort;
    }
  }
}

template <class T>
void Merge(T *pArray, const std::size_t l1, const std::size_t h1, const std::size_t l2, const std::size_t h2){
  std::size_t n = h2-l1+1;
  T *tmp = new T[n];
  std::size_t i1 = l1;
  std::size_t i2 = l2;
  std::size_t i = 0;
  while(i1<=h1 && i2 <= h2){
    if(*(pArray+i1) < *(pArray+i2)) {
      *(tmp+i) = *(pArray+i1);
      i1++;
    }else{
      *(tmp+i) = *(pArray+i2);
      i2++;
    }
    i++;
  }
  if(i1 > h1){
    while(i2<=h2){
      *(tmp+i) = *(pArray + i2);
      i2++;
      i++;
    }
  }
  if(i2 > h2){
    while(i1<=h1){
      *(tmp+i) = *(pArray + i1);
      i1++;
      i++;
    }
  }

  for(std::size_t idx=l1; idx<=h2; idx++){
    *(pArray+idx) = *(tmp+idx-l1);
  }
  delete[] tmp;
}
template <class T>
void MergeSort(T *pArray, const std::size_t low, const std::size_t high){
  int mid = floor((high-low)/2);
  
  if (low >= high ){return; }
  MergeSort(pArray, low, low+mid);
  MergeSort(pArray, low+mid+1, high);
  Merge(pArray, low, low+mid, low+mid+1, high);
}
template<class T>
void QuickSort(T* pArray, const std::size_t, lo, const std::size_t hi){
  int pivot = rand() % *(hi-lo);
  int i = lo, j = lo + pivot +1; 
  while(i< lo+pivot && j < hi){
    bool swapped = false;
    if ((*(pArray+i) > pivot) && (*(pArray+j) <= pivot)) {
      //swap elements
      T temp = *(pArray+i);
      *(pArray+i) = *(pArray+j);
      *(pArray+j) = temp;
      swapped = true;
    }
    if (!swapped){
      if(*(pArray+i) > pivot){	j++;  }else{ i++;  }
    }else{ i++;  j++; }
  }
  QuickSort(pArray, lo, pivot-1);
  QuickSort(pArray, pivot+1, hi);
}
template<class T>
void RandomizedQuickSort(T* pArray, const std::size_t n){
}
template<class T>
void HybridSort(T* pArray, const std::size_t n){
}
