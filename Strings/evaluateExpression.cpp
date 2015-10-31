#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
using namespace std;
class Stack{
public:
	void push(char val){
		elements.push_back(val);
	}
	void pop(){
		elements.pop_back();
	}
	char top() const{
		return elements.back();
	}
	bool isEmpty() const{
		return (elements.size() == 0);
	}
	int size() const{
		return elements.size();
	}
private:
	vector<char> elements;
};
class Solution {
private:
	int evaluateStack(Stack& expStack){
		Stack readOutStack;
		while(expStack.top() != '(' && !expStack.isEmpty()){
			readOutStack.push(expStack.top());
			expStack.pop();
		}
		
		if(expStack.top() == '(') { 
			expStack.pop();
		}

		if(readOutStack.isEmpty()) { return 0;}

		int sum = 0;
		stringstream ss;
		while(readOutStack.top() != '+' && readOutStack.top() != '-' && !readOutStack.isEmpty()){
			ss << readOutStack.top();
			readOutStack.pop();
		}
		if(!ss.str().empty()){
			sum= atoi(ss.str().c_str());
			cout << "Sum: " << sum << endl;
		}

		int mulFactor = 1, prevMulFactor = 1;
		bool isConsecutive = false;
		while(!readOutStack.isEmpty()){
			mulFactor = (readOutStack.top() == '+')?1:-1;
			if(isConsecutive ){
				mulFactor *= prevMulFactor;
			}
			readOutStack.pop();

			ss.str("");
			while(readOutStack.top() != '+' && readOutStack.top() != '-' && !readOutStack.isEmpty()){
				ss << readOutStack.top();
				readOutStack.pop();
			}
			if(!ss.str().empty()) {
				int op2 = atoi(ss.str().c_str());
				sum+= (mulFactor*op2);
				isConsecutive = false;
			}else{
				isConsecutive = true;
			}
			prevMulFactor = mulFactor;
			
		}
		return sum;
	}
public:
    int calculate(string s) {
    	int n = s.length();
    	if(n == 0) { return -1;};

    	Stack expStack;
    	int i=0; 
    	while(i<n){
    		if(s[i]!=' '){
    			if(s[i] != ')'){
    				expStack.push(s[i]);
    			}else{
    				int val = evaluateStack(expStack);
    				stringstream temp("");
    				temp << val;
    				for(auto x : temp.str()){
    					expStack.push(x);	
    				}
    			}
    		}
    		i++;
    	}
    	if(!expStack.isEmpty()){
    		return evaluateStack(expStack);
    	}else{
    		return 0;
    	}
    }
};
int main(int argc, char** argv){
	Solution s;
	string str = "1 + 1";
	int val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;

	str = "2-1 + 2 ";
	val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;	

	str = "(1+(4+5+2)-3)+(6+8)";
	val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;	

	str = "(";
	val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;	

	str = "";
	val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;	

	str = " ";
	val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;	

	str = "1+1-1";
	val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;	

	str = "0";
	val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;

	str = "2-(5-6)";
	val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;

	str = "2+(5-6)";
	val = s.calculate(str);
	cout << "String: " << str << " Val:" << val << endl;
	
}