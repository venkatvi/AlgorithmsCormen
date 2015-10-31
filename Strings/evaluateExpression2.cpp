#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;

class Solution {
private:
	string trimSpaces(string& s){
		stringstream ss;
		for(auto x:s){
			if(x != ' '){
				ss << x;
			}
		}		        
		return ss.str();
	}
	void constructExpressionArray(vector<int>& elements, map<int, char>& opIndices, string& s){
		stringstream ss;
		int n = s.length();
		for(int i=0; i<n; i++){
			char x = s[i];
			if(x == '+' || x == '-' || x == '*' || x == '/'){
				if(!ss.str().empty()){
					int val = atoi(ss.str().c_str());
					elements.push_back(val);
					ss.str("");
				}
				opIndices.insert({elements.size(), x});
				elements.push_back(-1);
			}else{
				ss << x;
			}
		}
		if(!ss.str().empty()){
			int val = atoi(ss.str().c_str());
			elements.push_back(val);
		}
	}
	int doBinaryOperation(int a, int b, char optr){
		switch(optr){
			case '*':
				//cout << "a: " << a << " b:" << b << endl;
				return a*b;
			case '/':
				return a/b;
			case '-':
				return a-b;
			case '+':
				return a+b;
		}
	}
	int doUnaryOperation(int a, char optr){
		switch(optr){
			case '-':
				return -1* a;
			case '+':
				return a;
			default:
				return a;
		}
	}
	bool isCandidateOp(bool isMulDivide, char optr){
		//cout << "IsMulDivide:" << isMulDivide << " Optr:" << optr << endl;
		if(isMulDivide){
			return (optr == '*' || optr == '/');
		}else{
			return (optr == '+' || optr == '-');
		}
	}
	string print(vector<int>& elements){
		stringstream ss;
		ss << "{";
		for(auto x : elements){
			ss << x << ",";
		}
		ss << "}";
		return ss.str();
	}
	string print(map<int, char>& opIndices){
		stringstream ss;
		ss << "{";
		for(auto x : opIndices){
			ss << x.first << ":" << x.second << ",";
		}
		ss << "}";
		return ss.str();	
	}
	int evaluateExpressions(vector<int>& elements, map<int, char>& opIndices, bool isMulDivide){
		vector<int> newElements;
		map<int, char> newOpIndices;
		int i=0;
		while(i<elements.size()){
			//cout << "Index: " << i << " element[i]" << elements[i] << endl;
			if(opIndices.find(i) != opIndices.end()){
				if(isCandidateOp(isMulDivide, opIndices[i])){
					//cout << "isCandidateOp: 1" << endl;
					if(elements[i+1] != -1 && !(elements[i+1] == 0 && opIndices[i] == '/')){
						if(newElements.size() > 0){
							int val = doBinaryOperation(newElements.back(), elements[i+1], opIndices[i]);
							newElements.pop_back();
							newElements.push_back(val);
							i+=2;
						}else{
							if(elements.size() > (i+1)){
								int val = doUnaryOperation(elements[i+1], opIndices[i]);
								newElements.push_back(elements[i+1]);
								i+=2;
							}else{
								return 1;
							}
						}
					}else{
						return 1;
					}
				}
				else{
					//cout << "isCandidateOp: 0" << endl;
					newElements.push_back(elements[i]);
					newOpIndices.insert({newElements.size()-1, opIndices[i]});
					i++;
				}
			}else{
				newElements.push_back(elements[i]);
				i++;
			}
			//cout << "New elements: " << print(newElements) << endl; 
		}
		elements = newElements;
		opIndices = newOpIndices;
		return 0;
	}

public:
    int calculate(string s) {
		int n = s.length();
		if(n==0){ return 0;}

		s = trimSpaces(s);
		n = s.length();

		vector<int> elements;
		map<int, char> opIndices;
		constructExpressionArray(elements, opIndices, s);
		//cout << "Elements: " << print(elements) << " Map: " << print(opIndices) << endl;
		
		int res = evaluateExpressions(elements, opIndices, true);
		if(res){return -1;}
		//cout << "Evaling */: " << print(elements) << endl; 
		
		res = evaluateExpressions(elements, opIndices, false);
		if(res) { return -1;}


		if(elements.size() == 1){
			return elements.back();
		}else{
			return -1;
		}
	}
};
int main(int argc, char** argv){
	Solution s;

	string expr  = "3+2*2";
	int val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;

	expr = " 3/2 ";
	val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;	

	expr = " 3+5 / 2 ";
	val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;

	expr = "+2";
	val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;

	expr = "-2";
	val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;

	expr = "+*";	
	val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;

	expr = "2+3*0/2";
	val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;

	expr = "2+3*2/0";
	val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;

	expr = "1-1+1";
	val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;

	expr = "12-3*4";
	val = s.calculate(expr);
	cout << "String:" << expr << " Val:" << val << endl;

}

