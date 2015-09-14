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
    cout << "Unable to open file"; 
  }
}

int main(int argc, char* argv[]){
  if (argc < 2) {
    cout << "Usage is -t <testCaseFile>\n";
    exit(0);
  }
  else{
    cout << argv[0] << "-" << argv[1] << "-" << argv[2] << endl;
    if (strcmp(argv[1], "-t") == 0){
        char* testCaseFile = argv[2];
        std::list<std::vector<int>> lTestCases;
	loadTestCasesForSortAlgorithms(lTestCases,testCaseFile);
	
        std::list<std::vector<int>>::iterator it;
	for(it=lTestCases.begin(); it != lTestCases.end(); ++it){
	  std::vector<int>& tmp = *it;
	  int* testCase = new int(tmp.size());
	  std::vector<int>::iterator itv;
	  std::size_t cntr = 0;
	  for(itv = tmp.begin(); itv!=tmp.end(); ++itv){
	    *(testCase+cntr) = *itv;
	    cntr++;
	  }
	  cout << "TestCase Before Sorting.. " << endl;
	  for(size_t i=0; i<tmp.size(); i++){
	    cout << *(testCase+i) << ",";
	  }
	  cout << endl;

	  std::chrono::time_point<std::chrono::system_clock> start, end;
	  start = std::chrono::system_clock::now();

	  SelectionSort(testCase, tmp.size());

	  end = std::chrono::system_clock::now();
	  

	  cout << "After sorting ... " << endl;
	  for(size_t i=0; i<tmp.size(); i++){
	    cout << *(testCase+i) << ",";
	  }
	  cout << endl;

	  std::chrono::duration<double> elapsed_seconds = end-start;
	  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  cout << "Elapsed Time: " << elapsed_seconds.count() << "s" << endl;
	  cout << "-------------------------------------------------------" << endl;
	}
    }
    else{
      cout << "Invalid argv" << endl;
    }
  }
}
