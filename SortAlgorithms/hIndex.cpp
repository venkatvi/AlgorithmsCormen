#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void merge(int* citations, const int low1, const int high1, const int low2, const int high2){
    int n = high2-low1+1;
    int* temp = new int[n];
    
    int i=low1;
    int j=low2;
    int k= 0;

    while(i<=high1 && j<=high2){
        if(*(citations+i) > *(citations+j)){
            *(temp+k) = *(citations+i);
            i++;
        }else{
            *(temp+k) = *(citations+j);
            j++;
        }
        k++;
    }

    if(i>high1){
        while(j<=high2){
            *(temp+k) = *(citations+j);
            k++;
            j++;
        }
    }

    if(j>high2){
        while(i<=high1){
            *(temp+k) = *(citations+i);
            k++;
            i++;
        }
    }
    for(int idx=low1; idx<=high2; idx++){
        *(citations+idx) = *(temp+idx-low1);
    }
    delete[] temp;
}

void mergeSort(int* citations, const int low, const int high){
    if (low >= high) { return;} 
    int mid = floor((high - low)/2);

    mergeSort(citations, low, low+mid);
    mergeSort(citations, low+mid+1, high);
    merge(citations, low, low+mid, low+mid+1, high);
}

int hIndex(int* citations, int citationsSize) {
   if (citationsSize == 1){
       if (citations[0] == 0){ return 0;}
       return 1;
   }
   mergeSort(citations, 0, citationsSize-1);
   for(int i=0; i<citationsSize; i++){
	printf("citations[%d]=%d\n", i, citations[i]);
   }
   for(int i=0; i<citationsSize; i++){
       if (citations[i] < i){
           if (i <= 0) { return 0;}
           return i;
       }
   }
}
int getHIndex(int* citations, const int low, const int high, const int citationsSize){
    printf("Low-%d, High-%d\n", low, high);
    
    int mid = floor((high-low)/2);   
    printf("Mid-%d", mid);


    int rank = citationsSize - (low+mid);
    printf("MidRank-%d,Citations[mid]=%d\n", rank, citations[low+mid]);
    if (low >= high) { 
        if (citations[low] < rank)
        { 
            return rank-1;
        }
    }

	
    if (citations[low+mid] < rank){
        //search in the lower half of the citations array
        return getHIndex(citations, low+mid+1, high, citationsSize);
    }else{
        //search from 0-mid
        return getHIndex(citations, low, low+mid, citationsSize);
    }
}

int hIndex1(int* citations, int citationsSize) {
    if (citationsSize == 1){
        if(citations[0] == 0) { return 0;}
        else{ return 1;}
    }
    return getHIndex(citations, 0, citationsSize-1, citationsSize);
}
int main(int argc, char** argv){
	int test[2] = {0, 1};
	int result = hIndex1(test, 2);
	printf("%d\n", result);
}
