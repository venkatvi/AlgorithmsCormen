#include <map>
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left; 
	TreeNode* right;
	TreeNode(int v): val(v), left(NULL), right(NULL){}
};
void gatherAllNodeValues(map<int,int>& values, TreeNode* root){
	if(!root) { return ;} 
	if(values.find(root->val) == values.end()){
		values.insert({root->val, 1});
	}
	if (!root->right && !root->left){ 
		return;
	}else{
		if (root->left) {
			gatherAllNodeValues(values, root->left);
		}
		if(root->right){
			gatherAllNodeValues(values, root->right);
		}
	}
}
bool checkIfNodesMatch(map<int,int>& values, TreeNode* root){
	if(!root) { return true;} 
	if(values.find(root->val) == values.end()){
		return false;
	}
	if (!root->right && !root->left){ 
		return true;
	}else{
		if (root->left) {
			checkIfNodesMatch(values, root->left);
		}
		if(root->right){
			checkIfNodesMatch(values, root->right);
		}
	}
	return true;
}
bool checkIfTwoTreesHaveSameIntegers(TreeNode* root1, TreeNode* root2){
	map<int, int> values; 
	gatherAllNodeValues(values, root1);
	return checkIfNodesMatch(values, root2);
}
void print(TreeNode* root){
	if (!root) { return; }
	cout << "Root: " << root->val;
	if(root->left && root->left->val != INT_MIN){
		cout << " Left: " << root->left->val;
	}else{
		cout << " Left: NULL ";
	}
	if (root->right && root->right->val != INT_MIN){
		cout << " Right: " << root->right->val;
	}else{
		cout << " Right: NULL ";
	}
	cout << "" << endl;
	print(root->left);
	print(root->right);
}
TreeNode* constructTreeFromLevelOrder(vector<int>& levelOrderNodes){
	if(levelOrderNodes.size() == 0){
		return NULL;
	}
	vector<TreeNode*> nodes;
	TreeNode* root = new TreeNode(levelOrderNodes[0]);
	nodes.push_back(root);

	if(levelOrderNodes.size() > 1){
		int i=0, j = 1;
		TreeNode* parent, *child;

		while(j < levelOrderNodes.size()){
			parent = nodes[i];
			child = new TreeNode(levelOrderNodes[j]);
			nodes.push_back(child);
			if(!parent->left ){
				parent->left = child;
				j++;
			}else if(!parent->right ){
				parent->right = child;
				j++; 
				i++;
			}
		}
	}
	return root;
}
int main(int argc, char** argv){
	vector<int> levelOrder1 {5, 1, 6, 5, 3, 4, 2};
	TreeNode* root1 = constructTreeFromLevelOrder(levelOrder1);

	vector<int> levelOrder2 {5, 1, 2, 3, 4, 6, 1};
	TreeNode* root2 = constructTreeFromLevelOrder(levelOrder2);

	bool result = checkIfTwoTreesHaveSameIntegers(root1, root2);

	cout << "Tree 1" << endl;
	print(root1);

	cout << "Tree 2" << endl;
	print(root2);

	cout << "Result: " << result << endl;
}