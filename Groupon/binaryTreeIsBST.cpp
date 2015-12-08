#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;
struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int val): val(val), left(NULL), right(NULL){}
};
string print(Node* n){
  stringstream ss;
  if(n){
    ss << "Node: " << n->val;
    if(n->left){
      ss << " Left:" << n->left->val << endl;
      ss << print(n->left);
    }
    if(n->right){
      ss << " Right:" << n->right->val << endl;
      ss << print(n->right);
    }
  }
  return ss.str();
}
class Solution{
private:
  bool isBSTUtil(Node* root, int min, int max){
    if(!root) { return true;} // trivially
    if(root && !root->left && !root->right){
      if(root->val >= min && root->val < max){
        return true;
      }else{
        return false;
      }
    }
    return isBSTUtil(root->left, min, root->val) && isBSTUtil(root->right, root->val, max);
  }
  void traverseInOrder(Node* root, vector<int>& inOrderTraversal){
    if(!root){ return;}
    if(root && !root->left && !root->right){
      inOrderTraversal.push_back(root->val);
    }
    traverseInOrder(root->left, inOrderTraversal);
    inOrderTraversal.push_back(root->val);
    traverseInOrder(root->right, inOrderTraversal);
  }
public:
  bool isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
  }
  bool isBST2(Node* root){
    vector<int> inOrderTraversal;
    traverseInOrder(root, inOrderTraversal);

    int prev = inOrderTraversal[0];
    for(int i=1; i<inOrderTraversal.size(); i++){
      if(inOrderTraversal[i] < prev){
        return false;
      }
      prev = inOrderTraversal[i];
    }
    return true;
  }
};
int main(int argc, char** argv){
  Solution s;
  Node* n = new Node(12);
  Node* left = new Node(6);
  Node* right = new Node(18);
  Node* leftleft = new Node(3);
  Node* leftright = new Node(9);
  Node* rightleft = new Node(15);
  Node* rightright = new Node(21);
  n->left = left;
  n->right = right;
  left->left = leftleft;
  left->right = leftright;
  right->left = rightleft;
  right->right = rightright;

  bool res = s.isBST(n);
  bool res2 = s.isBST2(n);
  cout << "Tree:" << print(n) << endl;
  cout << "IsBST:" << res << " 2:" << res2 << endl;

  delete n;
  delete left;
  delete right;
  delete leftleft;
  delete leftright;
  delete rightright;
  delete rightleft;
}
