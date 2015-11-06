#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    bool getRootToLeafPath(vector<TreeNode*>& path, TreeNode* root, TreeNode* q){
        if (!root){ return false; } 
        if (root == q) {
            path.push_back(q);
            return true;
        }
        else{
            if (root->left){
                if (getRootToLeafPath(path, root->left, q) ){
                    path.push_back(root);
                    return true;
                }
            }
            if(root->right){
                if(getRootToLeafPath(path, root->right, q)){
                    path.push_back(root);
                    return true;
                }
            }
        }
        return false;
    }

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) { return root; }
        if (!root->left && !root->right){ return root; }

        vector<TreeNode*> pPath, qPath; 
        bool isPPathFound = getRootToLeafPath(pPath, root, p);
        bool isQPathFound = getRootToLeafPath(qPath, root, q);

        if (!isPPathFound || !isQPathFound) { return NULL; }
        std::reverse(pPath.begin(), pPath.end());
        std::reverse(qPath.begin(), qPath.end());
       
	for(int j=0; j < pPath.size(); j++){
		cout << pPath[j]->val << endl;
	} 
	cout << "--------------" << endl;

	for(int j=0; j < qPath.size(); j++){
		cout << qPath[j]->val << endl;
	}
	cout << "-------------" << endl;
        int i=0;
        while(i < pPath.size() && i < qPath.size()){
            cout << pPath[i]->val << ": " << qPath[i]->val << endl;
            if (pPath[i]->val != qPath[i]->val){
                break;
            }
            i++;
        }
        cout << pPath[i-1]->val << endl;
    }
};
int main(int argc, char** argv){
	Solution S;
	TreeNode* a = new TreeNode(1);
	a->left = new TreeNode(2); 
	TreeNode* ans = S.lowestCommonAncestor(a, a, a->left);
	cout << ans->val << endl;
}
