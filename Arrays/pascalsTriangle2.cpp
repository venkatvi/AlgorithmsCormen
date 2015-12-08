#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> pascalsT;
        if(rowIndex == 0){ return pascalsT; }
    	
    	vector<int> rowOne(1, 1);
    	if(rowIndex == 1) { return rowOne;}

    	vector<int> rowTwo (2, 1);
    	if(rowIndex == 2) { return rowTwo;}
    	
    	vector<int> prevRow = rowTwo;
    	for(int i=2; i<rowIndex; i++){
    		int k = 0;
    		int numElements = prevRow.size();
    		
    		vector<int> newRow(numElements+1, 1);
    		for(int j=1; j< numElements; j++){
    			newRow[j] = prevRow[k] + prevRow[k+1];
    			k++;
    		}
    		prevRow = newRow;
    	}
    	return prevRow;
    }
};
string print(vector<int>& nums){
    stringstream ss;
    ss << "[";
    for(auto x: nums){
        ss << x << ",";
    }
    ss << "]";
    return ss.str();
}
int main(int argc, char** argv){
	Solution s;
	for(int i =0; i<10; i++){
		vector<int> pascalsT = s.getRow(i);
		cout << "NumRows: " << i << " PASCALS T: " << endl;
		cout << print(pascalsT) << endl;;
	}
}