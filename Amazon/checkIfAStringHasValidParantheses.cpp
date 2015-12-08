#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Stack {
	public:
		void push(char x){
			elements.push_back(x);
		}
		void pop(){
			elements.erase(elements.end()-1);
		}
		char top(){
			return elements.back();
		}
		bool isEmpty(){
			return (elements.size() == 0);
		}
	private:
		vector<char> elements;
};
// Input: map of paranthesis pairs - key: start paranethesis char, value: end paranthesis char
//       Input string
// Output: check if input string has valid set of paranthesis. (opening and closing)
//Idea: 
// maintain  a map from open paranthesis - > close paranthesis == MAP1 
//           a map from close paranthesis -> open paranthesis == MAP2 
// 1. Parse the string from left to write. 
// 2. As a paranthesis char is found from Map 1, insert it into stack 
// 3. As a paranthesis char is from from Map 2, pop stack
// Repeat 1-3 until end of string
// return true is stack is empty, otherwise false
bool checkIfStringHasValidParantheses(map<char, char>& paranthesisPairs, string& inputString){
	map<char, char> reverseParanthesisPair;
	for(auto x:paranthesisPairs){
		char key = x.first;
		char value = x.second;
		reverseParanthesisPair.insert({value, key});
	}
	Stack paraStack;
	for(auto x: inputString){
		if (paranthesisPairs.find(x) != paranthesisPairs.end()){
			paraStack.push(x);
		}
		if(reverseParanthesisPair.find(x) != reverseParanthesisPair.end()){
			char pairX = paraStack.top();
			if (reverseParanthesisPair[x] != pairX){
				return false;
			}
			paraStack.pop();
		}
	}
	return paraStack.isEmpty();
}
int main(int argc, char** argv){
	map<char, char> paranthesisPair;
	paranthesisPair.insert({'{', '}'});
	paranthesisPair.insert({'(', ')'});
	paranthesisPair.insert({'[', ']'});
	paranthesisPair.insert({'<', '>'});

	/* Test Cases */
	string s1("{}");
	bool isValid  = checkIfStringHasValidParantheses(paranthesisPair, s1);
	cout << "String: " << s1 << " Actual Answer: " << isValid << " Expected: " << true << endl;

	string s2("<ad675+-fkmfd>");
	isValid  = checkIfStringHasValidParantheses(paranthesisPair, s2);
	cout << "String: " << s2 << " Actual Answer: " << isValid << " Expected: " << true << endl;
	
	string s3("a");
	isValid  = checkIfStringHasValidParantheses(paranthesisPair, s3);
	cout << "String: " << s3 << " Actual Answer: " << isValid << " Expected: " << true << endl;

	string s4("{>");
	isValid  = checkIfStringHasValidParantheses(paranthesisPair, s4);
	cout << "String: " << s4 << " Actual Answer: " << isValid << " Expected: " << false << endl;
	
	string s5("<[((kskfhdbh7)");
	isValid  = checkIfStringHasValidParantheses(paranthesisPair, s5);
	cout << "String: " << s5 << " Actual Answer: " << isValid << " Expected: " << false << endl;
	
	string s6("[<<((shsf8))>>]");
	isValid  = checkIfStringHasValidParantheses(paranthesisPair, s6);
	cout << "String: " << s6 << " Actual Answer: " << isValid << " Expected: " << true << endl;

}
