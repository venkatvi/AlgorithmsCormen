#ifndef STACK_H
#define STACK_H
#include <vector>
template<typename T>
class Stack{
	public:
		Stack(){};
		~Stack(){};
		void push(const T& pObj);
		T pop();
		const T top() const;
		bool isEmpty() const;
		Stack clone();
		void print() const;
		
	private:
		std::vector<T> mList;
};
#endif
