
#include <stdio.h>
/**
 * Definition for a binary tree node.*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int val): val(val), left(NULL), right(NULL){}
 };


double getDelta(int nodeVal, double target){
    if (nodeVal < target){
        return (target - nodeVal);
    }else{
        return (nodeVal - target);
    }
}

int findClosestVal(struct TreeNode* root, double target, int closestValSoFar){
    if(!root) { return closestValSoFar;}
    if (getDelta(closestValSoFar, target) > getDelta(root->val, target)){
        closestValSoFar = root->val;
    }

    if(root->val < target){
        //check out right tree     
        return findClosestVal(root->right, target, closestValSoFar);
    }else{
        //check out left tree
        return findClosestVal(root->left, target, closestValSoFar);
    }
}

int closestValue(struct TreeNode* root, double target) {
    if(!root->left && !root->right) { return root->val; }
    int closestValSoFar = findClosestVal(root, target, root->val);

    printf("%d, %d, %f\n", closestValSoFar, root->val, target);
    printf("%f, %f\n", getDelta(closestValSoFar, target), getDelta(root->val, target));
    if (getDelta(closestValSoFar, target) > getDelta(root->val, target)) {
        return root->val;
    }
    return closestValSoFar;
}
int main(int argc, char** argv){
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	
	printf("%d\n",  closestValue(root, 3.714286));
}

