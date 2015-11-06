#include "Tree.h"
#include "TreeAlgorithms.hpp"
#include <iostream>
using namespace std;
int main(int argc, char** argv){
	Tree* root = new Tree(3);
	Tree* left = new Tree(2);
	Tree* right = new Tree(4);
	root->left = left;
	root->right = right; 

	findAllPathsWhichSumToValue(T, val);
	return 0;
}
