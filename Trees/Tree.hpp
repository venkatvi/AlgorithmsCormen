#ifndef TREE_H
#define TREE_H
class Tree{
	public:
		int val; 
		Tree* leftTree;
		Tree* rightTree;
		Tree(int pVal): val(pVal), leftTree(NULL), rightTree(NULL) {} 
};
#endif