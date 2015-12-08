#include <string>
#include <map>
#include <iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
    	int tn = t.length(), sn = s.length();
    	if(sn == 0) { return ""};
    	if(tn == 0) { return ""};
    	if(tn > sn) { return ""};
    	map<char, int> occurences;
    	for(auto x : t){
    		if(occurences.find(x) == occurences.end()){
    			ocurrences.insert({x, 1});
    		}else{
    			occurences[x] = occurences[x] + 1;
    		}
    	}

    	int end = 0, start=end, uniqueChars = 0;
    	int minWindowLen = sn, windowStart = 0, windowEnd = n-1;
    	map<char, int> mOccurences = occurences;
    	while(end < sn){
    		

    	}
    }
};
int main(int argc, char** argv){

}