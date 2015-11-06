#include <vector>
#include <string>
#include <iostream>
#include <sstream>	
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.size() > 0){
	    	int minLength = strs[0].length();
	        for(int i=1; i<strs.size(); i++){
	        	if(minLength > strs[i].length()){
	        		minLength = strs[i].length();
	        	}
	        }
	        stringstream ss("");
	        for(int i =0; i<minLength; i++){
	        	char charToMatch = strs[0][i];
	        	for(int j=1; j<strs.size(); j++){
	        		if(charToMatch != strs[j][i]){
	        			return ss.str();
	        		}
	     	    }
	     	    ss << charToMatch;
	        }
	        return ss.str();
		}
		else{
			return "";
		} 
    }
};
string print(vector<string>& strs){
	stringstream ss;
	ss << "{";
	for(int i=0; i<strs.size(); i++){
		ss << strs[i] << ",";
	}
	ss << "}";
	return ss.str();
}
int main(int argc, char** argv){
	//TestCases:
	Solution s;

	vector<string> strs;
	string longestCommonPrefix = s.longestCommonPrefix(strs);
	cout << "Strings: " << print(strs) << " LCP:" << longestCommonPrefix << "#" << endl;

	strs.clear();
	strs.push_back(" ");
	longestCommonPrefix = s.longestCommonPrefix(strs);
	cout << "Strings: " << print(strs) << " LCP:" << longestCommonPrefix << "#" << endl;

	strs.clear();
	strs.push_back(" ");
	strs.push_back(" ");
	longestCommonPrefix = s.longestCommonPrefix(strs);
	cout << "Strings: " << print(strs) << " LCP:" << longestCommonPrefix << "#" << endl;

	strs.clear();
	strs.push_back("a");
	strs.push_back("ab");
	longestCommonPrefix = s.longestCommonPrefix(strs);
	cout << "Strings: " << print(strs) << " LCP:" << longestCommonPrefix << "#" << endl;

	strs.clear();
	strs.push_back("a");
	strs.push_back("b");
	longestCommonPrefix = s.longestCommonPrefix(strs);
	cout << "Strings: " << print(strs) << " LCP:" << longestCommonPrefix << "#" << endl;

	strs.clear();
	strs.push_back("abcde");
	strs.push_back("f");
	longestCommonPrefix = s.longestCommonPrefix(strs);
	cout << "Strings: " << print(strs) << " LCP:" << longestCommonPrefix << "#" << endl;

	strs.clear();
	strs.push_back("abcde");
	strs.push_back("abcd");
	strs.push_back("abc");
	longestCommonPrefix = s.longestCommonPrefix(strs);
	cout << "Strings: " << print(strs) << " LCP:" << longestCommonPrefix << "#" << endl;

}