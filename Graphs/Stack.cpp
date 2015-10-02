#include "Stack.hpp"
#include <iostream>
using namespace std;

template<typename T>
void Stack<T>::push(const T& pObj){
	mList.push_back(pObj);
}

template<typename T>
T Stack<T>::pop() {
	T result;
	if (!mList.empty()){
		result = mList.back();
		mList.pop_back();
	}else{
		cerr << "List is empty" << endl;
	}
	return result;
}

template<typename T>
const T Stack<T>::top() const {
	T result;
	if (!mList.empty()){
		result =  mList.back();
	}else{
		cerr << "List is empty" << endl;
	}
	return result;
}

template<typename T>
bool Stack<T>::isEmpty() const {
	return (mList.empty());
}

template<typename T>
Stack<T> Stack<T>::clone(){
	Stack<T> S;
	for(auto it = mList.begin(); it != mList.end(); ++it){
		S.push(*it);
	}
	return S;
}

template<typename T>
void Stack<T>::print() const {
	cout << "Printing Stack... " << endl;
	for(auto it = mList.rbegin(); it != mList.rend(); ++it){
		cout << *it << endl;
	}
	cout << "End of printing... " << endl;
}

template class Stack<int>;
