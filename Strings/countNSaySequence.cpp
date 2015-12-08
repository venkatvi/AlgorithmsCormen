#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

class Solution {
private:
	void readSequenceAndUpdate(vector<std::pair<string, int>>& sequence, const string s){
		char prevChar = s[0];
		int prevCount = 1;
		for(int i=1; i<s.length(); i++){
			int num = atoi(&s[i]);
			if(prevChar == s[i]){
				prevCount++;
			}else{
				stringstream temp; 
				temp << prevChar;
				sequence.push_back({temp.str(), prevCount});
				prevChar = s[i];
				prevCount = 1;
			}
		}
		stringstream temp;
		temp << prevChar;

		sequence.push_back({temp.str(), prevCount});
	}
public:
    string countAndSay(int n) {
    	if( n < 1) { return ""; };
    	if (n == 1) { return "1"; };

        vector< std::pair<string, int> > sequence;
        sequence.push_back({"1", 1});
        for (int i=2; i<=n; i++){
        	stringstream ss;
        	for(auto x: sequence){
        		ss << x.second << x.first;
        	}
        	sequence.clear();
        	readSequenceAndUpdate(sequence, ss.str());
        }

        //vector should have the right sequences pushed inside
        //print it out.
        stringstream ss;
        for(auto x:sequence){
        	ss << x.second << x.first;
        } 
        //cout << "N: " << n << " sequence:" << ss.str() << endl;
        return ss.str();
    }
};
int main(int argc, char** argv){
	//TestCases:
	Solution s;	
	for(int i=0; i<10; i++){
		string temp =s.countAndSay(i);
		cout << "N: " << i << " Sequence:" << temp << endl;
	}
}