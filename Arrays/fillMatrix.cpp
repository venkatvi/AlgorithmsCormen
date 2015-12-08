#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
string print(vector<int>& nums){
	stringstream ss;
	ss << "{";
	for(auto x: nums){
		ss << x<< ", ";
	}
	ss << "}";
	return ss.str();
}
string print(vector<vector<int>>& nums){
	stringstream ss;
	ss << "{";
	for(auto x: nums){
		ss << print(x) << "; " << endl;
	}
	ss << "}";
	return ss.str();
}
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> spiralMat;
        if(n <=0) { return spiralMat;}
        
        vector<int> tempVector(n, 0);
        spiralMat.assign(n, tempVector);
        
        int rowIndex = 0, colIndex = n-1;
        bool isRow = true, rowFlip = false, colFlip = true;

        int i=1;
        while(i<=(n*n)){
        	if(isRow){
        		int j=0;
        		while(j < n && j > -1){
        			int index = (rowFlip)?n-j-1: j;
        			if(spiralMat[rowIndex][index] == 0){
        				spiralMat[rowIndex][index] = i;
        				i++;
        			}
        			j++;
        		}
        		isRow = false;
        		int negateFactor = (!rowFlip? -1: 0);
        		rowIndex = n - rowIndex + negateFactor;
        		rowFlip = !rowFlip;
        	}else{
        		int j=0;
        		while(j<n && j >-1){
        			int index = (!colFlip)?n-j-1:j;
        			if(spiralMat[index][colIndex] == 0){
        				spiralMat[index][colIndex] = i;
        				i++;
        			}
        			j++;
        		}
        		isRow = true;
        		int negateFactor = (colFlip ? -1: -2);
        		colIndex = n - colIndex + negateFactor;
        		colFlip = !colFlip;
        	}
        }
    	return spiralMat;
    }
};

int main(int argc, char** argv){
	Solution s;
	for(int i=0; i<5; i++){
		vector<vector<int>> spiralMat = s.generateMatrix(i);
		cout << "N: " << i << " SpiralMat: " << endl;
		cout << print(spiralMat) << endl;
	}
}