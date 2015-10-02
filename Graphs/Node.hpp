#ifndef NODE_H
#define NODE_H
template<typename T>
class Node{
	public:
		Node(const T& pVal):mVal(pVal){}
		~Node(){}
		T getVal() const{ return mVal;} 
		void setVal(const T& pVal) { mVal = pVal;}
	private: 
		T mVal;
		
};
#endif
