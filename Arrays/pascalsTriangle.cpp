#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> pascalsT;
        if(numRows == 0){ return pascalsT; }
    	
    	vector<int> rowZero(1, 1);
    	pascalsT.push_back(rowZero);
    	if(numRows == 1) { return pascalsT;}

    	vector<int> rowOne(2, 1);
    	pascalsT.push_back(rowOne);
    	if(numRows == 2) { return pascalsT;}
    	
    	
    	for(int i=2; i<numRows; i++){
    		int k = 0;
    		vector<int> prevRow = pascalsT[i-1];
    		int numElements = prevRow.size();
    		
    		vector<int> newRow(numElements+1, 1);
    		for(int j=1; j< numElements; j++){
    			newRow[j] = prevRow[k] + prevRow[k+1];
    			k++;
    		}
    		pascalsT.push_back(newRow);
    	}
    	return pascalsT;
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
string print(vector<vector<int>>& nums){
    stringstream ss;
    ss << "{";
    for(auto x: nums){
        ss << print(x) << endl;
    }
    ss << "}";
    return ss.str();
}
int main(int argc, char** argv){
	Solution s;
	for(int i =0; i<10; i++){
		vector<vector<int>> pascalsT = s.generate(i);
		cout << "NumRows: " << i << " PASCALS T: " << endl;
		cout << print(pascalsT) << endl;;
	}
}