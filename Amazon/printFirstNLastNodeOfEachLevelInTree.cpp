#include <vector>
#include <iostream>
using namespace std;
/*
Problem: Given a tree, print the first and the last node of every level of the tree
Solution Idea:
1. Do a level order traversal
2. Collect all nodes at a given level (for all levels) in  a tree
3. Iterate through each level, print the first and last member of the lsit of nodes at each level

Complexity:
Time: O(n) - traverse entire tree (BFS)
Space: O(n) - contain a vector of vector of nodes for each level. 
*/
struct TreeNode{
	int val;
	TreeNode* left; 
	TreeNode* right;
	TreeNode(int v): val(v), left(NULL), right(NULL){}
};
void getLevelOrderNodes(vector<vector<int>>& levelOrderNodes, TreeNode* root, int level){
	if(!root) { return;}
	if(levelOrderNodes.size()  >= (level + 1)){
		vector<int>& nodesAtGivenLevel = levelOrderNodes[level];
		nodesAtGivenLevel.push_back(root->val);
	}else{
		vector<int> temp;
		temp.push_back(root->val);
		levelOrderNodes.push_back(temp);
	}
	if(root->left){
		getLevelOrderNodes(levelOrderNodes, root->left, level+1);
	}
	if(root->right){
		getLevelOrderNodes(levelOrderNodes, root->right, level+1);
	}
	return;
}
void printFirstNLastNodeOfEachLevel(TreeNode* root){
	vector<vector<int>> levelOrderNodes;
	getLevelOrderNodes(levelOrderNodes, root, 0);

	for(auto& x : levelOrderNodes){
		if(x.front() != x.back()){
			cout << " " << x.front() <<  " " << x.back();
		}else{
			cout << " " << x.back() ;
		}
	}
	cout << endl;
}
int main(int argc, char** argv){
	//TestCases:
	//Case 1: empty tree
	printFirstNLastNodeOfEachLevel(NULL);
	cout << "-------------------------------" << endl;

	//Case 2: one node
	printFirstNLastNodeOfEachLevel(new TreeNode(5));
	cout << "-------------------------------" << endl;

	//Case 3: One child node
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(6);
	printFirstNLastNodeOfEachLevel(root);
	cout << "-------------------------------" << endl;

	//Case 4: Tree which has only one child at each level alternating the left and right subtrees 
	root = new TreeNode(5);
	root->right = new TreeNode(6);
	root->right->left = new TreeNode(7);
	printFirstNLastNodeOfEachLevel(root);
	cout << "-------------------------------" << endl;

	//Case 5: complete binary tree
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	printFirstNLastNodeOfEachLevel(root);
	cout << "-------------------------------" << endl;
}