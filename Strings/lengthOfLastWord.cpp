#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> subStrings;
        stringstream ss("");
        for(int i=s.length()-1; i>=0;i--){
        	if(s[i] == ' '){
        		string temp = ss.str();
        		cout << "###" << temp << "###" << endl;
        		if(!temp.empty()){
        			subStrings.push_back(temp);
        			ss.str("");
        		}
        		if(subStrings.size() > 0) {
        			break;
        		}
        	}else{
        		ss << s[i];
        	}
        }
        
    	//no spaces found. 
    	//push all of ss.str into vector. return its length
    	string temp = ss.str();
    	if(!temp.empty()){
    		subStrings.push_back(temp);
    	}
    
        if(subStrings.size() > 0){
    		return (subStrings.back().length());
    	}
    	return 0;
    }
};
int main(int argc, char** argv){
	//TestCases:
	Solution s;
	string str("");
	int l = s.lengthOfLastWord(str);
	cout << "String:" << str << " Length:" << l << endl;

	str = "a "; 
	l = s.lengthOfLastWord(str);
	cout << "String:" << str << " Length:" << l << endl;

	str = "abc";
	l = s.lengthOfLastWord(str);
	cout << "String:" << str << " Length:" << l << endl;

	str = " abc";
	l = s.lengthOfLastWord(str);
	cout << "String:" << str << " Length:" << l << endl;

	str = "abc def ";
	l = s.lengthOfLastWord(str);
	cout << "String:" << str << " Length:" << l << endl;

	str = "abc def gfh";
	l = s.lengthOfLastWord(str);
	cout << "String:" << str << " Length:" << l << endl;

}