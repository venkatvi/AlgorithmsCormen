#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
    	int rowCount = 0;
    	int toAdd = 1;
    	vector<vector<char>> zigZagOrder;
    	for(int i=0; i<numRows; i++){
    		vector<char> temp;
    		zigZagOrder.push_back(temp);
    	}
    	if(zigZagOrder.size() > 0){
	    	for(int i=0; i < s.length(); i++){
	    		zigZagOrder[rowCount].push_back(s[i]);
	    		rowCount = rowCount + toAdd;
	    		if(rowCount == numRows){
	    			toAdd = -1;
	    			rowCount = rowCount + toAdd;
	    			if(rowCount > 0){
	    				rowCount = rowCount + toAdd;
	    			}
	    		}else if (rowCount == -1){
	    			toAdd = 1;
	    			rowCount = rowCount + toAdd;
	    			if(rowCount < (numRows-1)){
	    				rowCount = rowCount + toAdd;
	    			}
	    		}
	       	}
       }
       	stringstream ss("");
       	for(int i=0; i<zigZagOrder.size(); i++){
       		for(int j=0; j<zigZagOrder[i].size(); j++){
       			ss << zigZagOrder[i][j];
       		}
       	}    
       	return ss.str();
    }
};
int main(int argc, char** argv){
	Solution s;

	string str("");
	string zigZag = s.convert(str, 0);
	cout << "String:" << str << " ZigZagOrder:" << zigZag << endl;

	str = "a";
	zigZag = s.convert(str, 0);
	cout << "String:" << str << " ZigZagOrder:" << zigZag << endl;

	str = "a";
	zigZag = s.convert(str, 1);
	cout << "String:" << str << " ZigZagOrder:" << zigZag << endl;

	str = "a";
	zigZag = s.convert(str, 2);
	cout << "String:" << str << " ZigZagOrder:" << zigZag << endl;

	str = "PAYPALISHIRING";
	zigZag = s.convert(str, 3);
		cout << "String:" << str << " ZigZagOrder:" << zigZag << endl;

	str = "ab";
	zigZag = s.convert(str, 2);
	cout << "String:" << str << " ZigZagOrder:" << zigZag << endl;

	str = "abc";
	zigZag = s.convert(str, 2);
	cout << "String:" << str << " ZigZagOrder:" << zigZag << endl;

	str = "abcde";
	zigZag = s.convert(str, 1);
	cout << "String:" << str << " ZigZagOrder:" << zigZag << endl;

}