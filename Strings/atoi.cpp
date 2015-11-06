#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <limits.h>
#include <ctype.h>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
    	try{
    		if(str.length() == 0){
	    		throw str;
	    	}
	    	stringstream ss;
	    	string trimmedStr("");
	    	int i=0;
	    	bool firstNonSpaceFound = false;
	    	while(i < str.length()){
	    		if(isspace(str[i])){
	    			if(!firstNonSpaceFound){
	    				i++;
	    				continue;
	    			}else{
	    				break;
	    			}
	    		}else{
	    			if(!firstNonSpaceFound){
	    				firstNonSpaceFound = true;
	    			}
	    			ss << str[i];
	    		}
	    		i++;
	    	}
	    	//nospaces found
	    	trimmedStr = ss.str();
	    	int startIndex = 0;
	    	if(trimmedStr[0] == '+' || trimmedStr[0] == '-'){
	    		startIndex = 1;
	    	}
	    	long num = 0; 
	    	for(int i = startIndex; i<trimmedStr.length(); i++){
	    		int temp = trimmedStr[i];
	    		if(temp < 48 || temp > 57){
	    			break; //Break at first non number char
	    		}else{
	    			long numBefore = num;
	    			num = num*10 +(temp - 48); //MIGHT WRAP AROUND TO A VALUE WITHIN INT LIMITS ?? ? ? ? 
	    			if((numBefore > 0 && num < 0) || (numBefore > num)){
	    				if(trimmedStr[0] == '-'){
	    					return INT_MIN;
	    				}else{
	    					return INT_MAX;
	    				}
	    			}
	    		}
	    	}
	    	if(trimmedStr[0] == '-'){
	    		num*=-1;
	    	}
	    	if(num < INT_MIN) { 
	    		return INT_MIN;
	    	}else if(num > INT_MAX){
	    		return INT_MAX;
	    	}
	    	return num;
    	}catch(string e){
    		return 0;
    	}
    	catch(char ePair){
    		return 0;
    	}
    	return 0;
    }
};
int main(int argc, char** argv){
	Solution s;
	//TestCases:
	string str = "";
	int num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = " ";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = " 1";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = "-1";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = " -2";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	stringstream ss;
	ss << INT_MAX;
	str = ss.str();
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	ss.str("");
	ss << "-" << INT_MAX;
	str = ss.str();
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	ss.str("");
	ss  << INT_MIN*-1 << endl;
	str = ss.str();
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	ss.str("");
	ss << INT_MIN << endl;
	str = ss.str();
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	ss.str("");
	ss << LONG_MAX << endl;
	str = ss.str();
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	ss.str("");
	ss << "-" << LONG_MAX << endl;
	str = ss.str();
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	ss.str("");
	ss << LONG_MIN*-1 << endl;
	str = ss.str();
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = "abs";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = "1200383";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = "-12238475";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = "               -384";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = "  384 2";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = "-0012a42";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;

	str = "18446744073709551617";
	num = s.myAtoi(str);
	cout << "String:" << str << " myAtoi:" << num << " stdlibAtoi:" << atoi(str.c_str()) << endl;


}