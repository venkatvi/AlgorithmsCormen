#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int pVal):val(pVal), left(NULL), right(NULL){}
};
class Solution{
private:
  void inOrderTraversal(Node* root, vector<int>& inOrderNodes){
    if(!root){ return;}
    if(root && !root->left && !root->right){ inOrderNodes.push_back(root->val); return;}
    if(root->left){
      inOrderTraversal(root->left, inOrderNodes);
    }
    inOrderNodes.push_back(root->val);
    if(root->right){
      inOrderTraversal(root->right, inOrderNodes);
    }
  }
  void preOrderTraversal(Node* root, vector<int>& preOrderNodes){
    if(!root){ return;}
    if(root && !root->left && !root->right){ preOrderNodes.push_back(root->val); return;}
    preOrderNodes.push_back(root->val);
    if(root->left){
      preOrderTraversal(root->left, preOrderNodes);
    }
    if(root->right){
      preOrderTraversal(root->right, preOrderNodes);
    }
  }
public:
  vector<vector<int>> encodeTree(Node* root){
    vector<int> inOrderNodes;
    inOrderTraversal(root, inOrderNodes);

    vector<int> preOrderNodes;
    preOrderTraversal(root, preOrderNodes);
    vector<vector<int>> encodedTree = {inOrderNodes, preOrderNodes};
    return encodedTree;
  }
  Node* decodeTree(vector<vector<int>>& orderedNodes){
    //parse tree from inorder and post or
    vector<int> inOrder = orderedNodes[0];
    vector<int> preOrder = orderedNodes[1];

    if(inOrder.size() !=  preOrder.size()){
      return NULL;
    }

    return decodeFromDifferentOrdering(inOrder, preOrder, 0, inOrder.size()-1, 0, preOrder.size()-1);

  }
  Node* decodeFromDifferentOrdering(vector<int>& inOrder, vector<int>& preOrder, int iS, int iE, int pS, int pE){
    if(iS >= inOrder.size() || iE >= inOrder.size()){ return NULL;}
    if(pS >= preOrder.size() || pE >= preOrder.size()){ return NULL;}
    int rootVal = preOrder[pS];
    Node* root = new Node(rootVal);

    int leftEnd = iS;
    for(int i=iS; i<iE; i++){
      if(inOrder[i] == rootVal){
        leftEnd = i-1;
        int leftPS = pS+1;
        int leftPE = pS + 1 + (i-iS);
        Node* leftNode = decodeFromDifferentOrdering(inOrder, preOrder, iS, leftEnd, leftPS, leftPE);
        root->left = leftNode;

        Node* rightNode = decodeFromDifferentOrdering(inOrder, preOrder, i+1, iE, leftPE+1, pE);
        root->right = rightNode;
        break;
      }
    }
    return root;
  }
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
string print(vector<int>& nums){
  stringstream ss;
  ss << "{";
  for(auto x : nums){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}
string print(vector<vector<int>>&  nums){
  stringstream ss;
  ss << "{";
  for(auto x : nums){
    ss << print(x) << ",";
  }
  ss << "}";
  return ss.str();
}
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
  cout << "Input Tree:" << endl;
  cout << print(n) << endl;

  vector<vector<int>> encodedTree = s.encodeTree(n);
  cout << "Encoded Tree:" << print(encodedTree) << endl;

  Node* newRoot = s.decodeTree(encodedTree);
  cout << "DecodedTree:" << endl;
  cout << print(newRoot) << endl;
}
