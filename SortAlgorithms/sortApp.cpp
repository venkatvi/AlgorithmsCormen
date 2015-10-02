#include <iostream>

#include <chrono>

#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "SortAlgorithms.hpp"

using namespace std;

enum ALGORITHM_TYPE{
  SELECTION_SORT=1,
  INSERTION_SORT,
  MERGE_SORT,
  QUICK_SORT
};
void loadTestCasesForSortAlgorithms(std::list<std::vector<int>>& lTestCases, const char* testCaseFile){
  string line;
  ifstream tcFileStream(testCaseFile);
  if(tcFileStream.is_open()){
    
    while(getline(tcFileStream, line)){
      std::vector<int> vInputArray;
      size_t pos = 0;
      char* token; 
      char* tcStr = const_cast<char*>(line.c_str());
      token = strtok(tcStr, ",");
      while(token != NULL){
	vInputArray.push_back(atoi(token));
        token = strtok(NULL, ",");
      }
      lTestCases.push_back(vInputArray);
    }
    tcFileStream.close();
  }
  else{
    std::cout << "Unable to open file"; 
  }
}

void copyVectorToArray(const std::vector<int>& tmp, int* pArray){
  std::vector<int>::const_iterator itv;
  std::size_t cntr = 0;
  for(itv = tmp.begin(); itv!=tmp.end(); ++itv){
    *(pArray+cntr) = *itv;
     cntr++;
  }
}
void printArray(const int* pArray, const std::size_t n, const std::string textToPrint){
  std::cout << "TestCase " <<  textToPrint << std::endl;
  for(std::size_t i=0; i<n; i++){
    std::cout << *(pArray+i) << ",";
  }
  std::cout << std::endl;

}
void sortNTime(int* pArray, const std::size_t n, const ALGORITHM_TYPE algorithmType){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  switch(algorithmType){
  case ALGORITHM_TYPE::SELECTION_SORT:
    SelectionSort(pArray, n);
    break;
  case ALGORITHM_TYPE::INSERTION_SORT:
    InsertionSort(pArray, n);
    break;
  case ALGORITHM_TYPE::MERGE_SORT:
    MergeSort(pArray, 0, n-1);
    break;
  default: 
    break;
  }
  end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout << "Elapsed Time: " << elapsed_seconds.count() << "s" << std::endl;

}
int main(int argc, char* argv[]){
  if (argc < 2) {
    cout << "Usage is -t <testCaseFile>\n";
    exit(0);
  }
  else{
    cout << argv[0] << "-" << argv[1] << "-" << argv[2] << endl;
    if (strcmp(argv[1], "-f") == 0){
        char* testCaseFile = argv[2];

	// load test cases 
        std::list<std::vector<int>> lTestCases;
	loadTestCasesForSortAlgorithms(lTestCases,testCaseFile);
	
	// load list of testcases and convert to vector
        std::list<std::vector<int>>::iterator it;
	for(it=lTestCases.begin(); it != lTestCases.end(); ++it){
	  std::vector<int>& tmp = *it;
	  
	  size_t n = tmp.size();

	  int* testCase = new int[n];
	  copyVectorToArray(tmp, testCase);

	 
	  printArray(testCase, n, " before sorting");
	  sortNTime(testCase, n, ALGORITHM_TYPE::MERGE_SORT);
	  printArray(testCase, n, " after sorting");
	  
	  std::cout << "-------------------------------------------------------" << std::endl;

	  delete[] testCase;
	  testCase = NULL;
	}
    }
    else{
      cout << "Invalid argv" << endl;
    }
  }
}
