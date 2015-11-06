#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Stack{
public:
	void push(char a){
		elements.push_back(a);
	}
	void pop(){
		elements.pop_back();
	}
	char top(){
		return elements.back();
	}
	bool isEmpty() const {
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
	bool isOpenParanthesis(char a){
		return (a == '(' || a == '[' || a == '{' || a == '<');
	}
	bool containsValidCharacters(string s){
		char parantheses[8] = { '(', ')', '{', '}', '[', ']', '<', '>'};
		bool paranthesesFound = false;
		for(int i=0; i<8; i++){
			if(s.find(parantheses[i]) != string::npos){
				paranthesesFound = true;
			}
		}
		return paranthesesFound;
	}
public:
    bool isValid(string s) {
    	if(s.length() <= 1){return false;}
    	if((s.length() % 2) == 1){return false;}
    	if(!containsValidCharacters(s)) { return false;}

    	map<char, char> paranthesisPairs;
    	paranthesisPairs.insert({'(', ')'});
    	paranthesisPairs.insert({'[', ']'});
    	paranthesisPairs.insert({'{', '}'});
    	paranthesisPairs.insert({'<', '>'});

    	Stack st;
        for(auto& x:s){
        	if(isOpenParanthesis(x)){
        		st.push(x);
        	}else{
        		if(st.size() >= 1){
	        		char top = st.top();
	        		if(paranthesisPairs.find(top) != paranthesisPairs.end()){
	        			if( paranthesisPairs[top] != x){
		        			return false;
		        		}
		        		st.pop();
	        		}else{
	        			return false;
	        		}
        		}else{
        			//there is nothing to pop/ invalid pair
        			return false;
        		}
        	}
        }
        return (st.isEmpty());
    }
};
int main(int argc, char** argv){
	Solution s;
	//TestCases:
	//Case 1:
	//Empty string;
	string test("");
	cout << "String: " <<  test << " isValid:" << s.isValid(test) << endl;

	//Case 2:
	test = "(";
	cout << "String: " <<  test << " isValid:" << s.isValid(test) << endl;

	//Case 2:
	test = "]";
	cout << "String: " <<  test << " isValid:" << s.isValid(test) << endl;

	//Case 2:
	test = ")}{({))[{{[}";
	cout << "String: " <<  test << " isValid:" << s.isValid(test) << endl;	

	//Case 3:
	test = "ab";
	cout << "String: " <<  test << " isValid:" << s.isValid(test) << endl;

	//Case 4:
	test = "()";
	cout << "String: " <<  test << " isValid:" << s.isValid(test) << endl;

	//Case 5:
	test = "(]";
	cout << "String: " <<  test << " isValid:" << s.isValid(test) << endl;

	//Case 6:
	test = "()[]{}<>";
	cout << "String: " <<  test << " isValid:" << s.isValid(test) << endl;

	//Case 7:
	test = "([{<>}]()[]<>)";
	cout << "String: " <<  test << " isValid:" << s.isValid(test) << endl;	

}