#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
    	if(s.length() == 0){
        	return 0;
        }
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        map<char, int> romanHash;
        romanHash.insert({'I', 1});
        romanHash.insert({'V', 5});
        romanHash.insert({'X', 10});
        romanHash.insert({'L', 50});
        romanHash.insert({'C', 100});
        romanHash.insert({'D', 500});
        romanHash.insert({'M', 1000});
        
        int allSum = 0;
        int i=0;
        while(i < s.length()){
        	if((romanHash.find(s[i]) != romanHash.end()) && (i < s.length()-1 && romanHash.find(s[i+1]) != romanHash.end())){
	        	if(romanHash[s[i]] < romanHash[s[i+1]]){
	        		int val = romanHash[s[i+1]] - romanHash[s[i]];
	        		allSum += val;
	        		i+=2;
	        	}else{
	        		allSum += romanHash[s[i]]; 
	        		i++;
	        	}
        	}else{
        		if((romanHash.find(s[i]) == romanHash.end()) || (i < s.length()-1 && romanHash.find(s[i+1]) == romanHash.end())){
        			return 0;
        		}else{
        			allSum += romanHash[s[i]];
        			return allSum;
        		}
        	}
        }
        return allSum;
    }
};
int main(int argc, char** argv){
	Solution s;
	//TestCases:
	string str("");
	int intVal = s.romanToInt(str);
	cout << "String:" << str << " Integer:" << intVal << endl;

	str = "LIII";
	intVal = s.romanToInt(str);
	cout << "String:" << str << " Integer:" << intVal << endl;

	str = "LIII";
	intVal = s.romanToInt(str);
	cout << "String:" << str << " Integer:" << intVal << endl;

	str = "L";
	intVal = s.romanToInt(str);
	cout << "String:" << str << " Integer:" << intVal << endl;

	str = "XL";
	intVal = s.romanToInt(str);
	cout << "String:" << str << " Integer:" << intVal << endl;

	str = "MMMCMXCIX";
	intVal = s.romanToInt(str);
	cout << "String:" << str << " Integer:" << intVal << endl;

	str = "abc";
	intVal = s.romanToInt(str);
	cout << "String:" << str << " Integer:" << intVal << endl;

	str = "XCii";
	intVal = s.romanToInt(str);
	cout << "String:" << str << " Integer:" << intVal << endl;

}