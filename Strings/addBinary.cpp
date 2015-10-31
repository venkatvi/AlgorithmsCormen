#include <string>
#include <bitset>
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
private:
	int addTwoBits(char* output, const int a, const int b, const int carryOver){
		int sum = a + b + carryOver;
		if(sum == 3){
			*output = '1';
			return 1;
		}else if(sum == 2){
			*output = '0';
			return 1;
		}else if(sum == 1){
			*output = '1';
			return 0;
		}else{
			*output = '0';
			return 0;
		}
	}
public:
    string addBinary(string a, string b) {
  		int m = 0, n = 0;
  		string longerString("");
  		string otherString("");
  		if(a.length() > b.length()){
  			m = a.length();
  			n = b.length();
  			longerString = a;
  			otherString = b;
  		}else{
  			m = b.length();
  			n = a.length();
  			longerString = b;
  			otherString = a;
  		}
  		string output(m, '0');
  		int carryOver = 0;
  		for(int i=0; i<n; i++){
  			carryOver = addTwoBits(&output[m-i-1], otherString[n-i-1]-48, longerString[m-i-1]-48, carryOver);
  		}
  		for(int i=m-n-1; i>=0; i--){
  			carryOver = addTwoBits(&output[i], longerString[i]-48, carryOver, 0);
  		}
  		if(carryOver == 1){
  			stringstream ss;
  			ss << "1" << output;
  			return ss.str();
  		}
  		return output;
    }
};
int main(int argc, char** argv){
	Solution s;

	//TestCases:
	//Case 1:
	string a("0");
	string b("0");
	string c = s.addBinary(a,b);
	cout << "Output a:" << a << " b:" << b << " c:" << c << endl;

	//Case 2:
	a = "1";
	b = "0";
	c = s.addBinary(a,b);
	cout << "Output a:" << a << " b:" << b << " c:" << c << endl;

	//Case 3:
	a = "1";
	b = "1";
	c = s.addBinary(a,b);
	cout << "Output a:" << a << " b:" << b << " c:" << c << endl;
	
	//Case 4:
	a = "11";
	b = "11";
	c = s.addBinary(a,b);
	cout << "Output a:" << a << " b:" << b << " c:" << c << endl;

	//Case 5:
	a = "1001";
	b = "1111";
	c = s.addBinary(a,b);
	cout << "Output a:" << a << " b:" << b << " c:" << c << endl;	

	//Case 5:
	a = "1";
	b = "1111";
	c = s.addBinary(a,b);
	cout << "Output a:" << a << " b:" << b << " c:" << c << endl;	

	//Case 5:
	a = "100";
	b = "110010";
	c = s.addBinary(a,b);
	cout << "Output a:" << a << " b:" << b << " c:" << c << endl;	



}