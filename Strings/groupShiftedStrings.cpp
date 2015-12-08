#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
    	vector<vector<string>> groups;

    	if (strings.size() == 0) { return groups;} 
    	std::sort(strings.begin(), strings.end());

    	vector<bool> ided(strings.size(), false); 
    	
        for(int k=0; k<strings.size(); k++){
			string curString(strings[k]);
			if(ided[k] == false){
        		ided[k] = true;
        		vector<string> group; 
        		group.push_back(curString);
        		
	        	int j = 0;
	        	while(j <= 25){ // 26th shift brings it back to x
	        		stringstream ss;
		        	for(int i=0; i<curString.length(); i++){
		        		char temp = (curString[i] + 1) > 122 ? curString[i] + 1 - 123 + 97: curString[i]+1; 
		        		ss << temp;
			        }
			        curString = ss.str();
			        for(int m=k+1; m < strings.size(); m++){
			        	if(strings[m] == curString){
			        		ided[m] = true;
			        		group.push_back(curString);
			        	}
			        }
			        j++;
	    		}
	    		groups.push_back(group);
	    	}
        }
        /*auto value_compare = [](vector<string> group1, vector<string>& group2){
        	return (group1[0] < group2[0]);
        };
        std::sort(groups.begin(), groups.end(), value_compare);*/
        return groups;
    }
};
string print(vector<string>strings){
	stringstream ss;
	ss << "{";
	for(auto x: strings){
		ss << x << ",";
	}
	ss << "}";
	return ss.str();
}
string printGroup(vector<vector<string>> groups){
	stringstream ss;
	ss << "{";
	for(auto x:groups){
		ss << print(x) << ";";
	}
	ss << "}";
	return ss.str();
}
int main(int argc, char** argv){
	Solution s;
	//testCases:
	vector<string> strings = {"fpbnsbrkbcyzdmmmoisaa",
"cpjtwqcdwbldwwrryuclcngw",
"a",
"fnuqwejouqzrif",
"js",
"qcpr",
"zghmdiaqmfelr",
"iedda",
"l",
"dgwlvcyubde",
"lpt",
"qzq",
"zkddvitlk",
"xbogegswmad",
"mkndeyrh",
"llofdjckor",
"lebzshcb",
"firomjjlidqpsdeqyn",
"dclpiqbypjpfafukqmjnjg",
"lbpabjpcmkyivbtgdwhzlxa",
"wmalmuanxvjtgmerohskwil",
"yxgkdlwtkekavapflheieb",
"oraxvssurmzybmnzhw",
"ohecvkfe",
"kknecibjnq",
"wuxnoibr",
"gkxpnpbfvjm",
"lwpphufxw",
"sbs",
"txb",
"ilbqahdzgij",
"i",
"zvuur",
"yfglchzpledkq",
"eqdf",
"nw",
"aiplrzejplumda",
"d",
"huoybvhibgqibbwwdzhqhslb",
"rbnzendwnoklpyyyauemm"};//{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};//{"abc", "def", "az", "ba", "abcde", "a", "a"};
	vector<vector<string>> groups = s.groupStrings(strings);
	cout << "Strings: " << print(strings) << " Groups: " << printGroup(groups) << endl;

}