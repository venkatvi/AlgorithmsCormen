#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
private:
	void getKey(string& key, const vector<int>& charSet){
		stringstream ss;
 		for(int i=0; i<charSet.size(); i++){
 			char temp = i+97;
 			for(int j = 0; j < charSet[i]; j++){
 				ss << temp;
 			}
 		}
 		key = ss.str();
	}
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	for(auto& str : strs){
     		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
     	}
     	std::sort(strs.begin(), strs.end());

     	unordered_map<string, vector<string>> anagramMap;
     	string anagramMapKey; 
     	for(auto& x : strs){
     		vector<int> charSet(26, 0);
     		for(int i=0; i<x.length(); i++){
     			++charSet[x[i]-97];
     		}
     		getKey(anagramMapKey, charSet);
     		
     		if(anagramMap.find(anagramMapKey) == anagramMap.end()){
     			vector<string> tempVector = {x};
     			anagramMap.insert({anagramMapKey, tempVector});
     		}else{
     			anagramMap[anagramMapKey].push_back(x);
     		}
     	}
     	vector<vector<string>> anagramGroups;
     	for(auto& x: anagramMap){
     		anagramGroups.push_back(x.second);
     	}
     	std::reverse(anagramGroups.begin(), anagramGroups.end());
     	return anagramGroups;
    }
};
string print(const vector<string>& strings){
	stringstream ss;
	ss << "{";
	for(auto& x:strings){
		ss << x << ",";
	}
	ss << "}";
	return ss.str();
}
string printGroup(const vector<vector<string>>& groups){
	stringstream ss;
	ss << "{";
	for(auto& x : groups){
		ss << print(x) << ";";
	}
	ss << "}";
	return ss.str();
}
int main(int argc, char** argv){
	//TestCases:
	Solution s;
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> anagramGroups = s.groupAnagrams(strs);
	cout << "Input strings:" << print(strs) << " AnagramGroups:" << printGroup(anagramGroups) << endl;

	strs.clear();
	anagramGroups.clear();
	strs.push_back("abc");
	strs.push_back("net");
	strs.push_back("game");
	anagramGroups = s.groupAnagrams(strs);
	cout << "Input strings:" << print(strs) << " AnagramGroups:" << printGroup(anagramGroups) << endl;	

	strs.clear();
	anagramGroups.clear();
	anagramGroups = s.groupAnagrams(strs);
	cout << "Input strings:" << print(strs) << " AnagramGroups:" << printGroup(anagramGroups) << endl;	

}