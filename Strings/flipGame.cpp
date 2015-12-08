#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
    	vector<string> output;
    	if(s.length() == 0) { return output;}
        for(int i=0; i<s.length()-1; i++){
        	if(s[i] == '+' && s[i+1] == '+'){
        		string temp(s);
        		temp[i] = '-'; temp[i+1] = '-';
        		output.push_back(temp);
        	}
        }
        return output;
    }
};
string print(vector<string>& output){
	stringstream ss;
	ss << "{";
	for(auto& x : output){
		ss << x << "," ;
	}
	ss << "}";
	return ss.str();
}
int main(int argc, char** argv){
	Solution s;
	string str = "";
	vector<string> output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

	str = "a";
	output.clear();
	output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

	str = "++";
	output.clear();
	output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

	str = "+";
	output.clear();
	output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

	str = "+++";
	output.clear();
	output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

	str = "---";
	output.clear();
	output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

	str = "+-+-+-";
	output.clear();
	output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

	str = "+++++++++++++++";
	output.clear();
	output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

	str = "++--++--++--++--";
	output.clear();
	output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

	str = "++-+++--++++---+++++----";
	output.clear();
	output = s.generatePossibleNextMoves(str);
	cout << "Flip game input: " << str << " Output: " << print(output) << endl;

}