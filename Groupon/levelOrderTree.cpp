#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
string print(vector<int>& nums){
  stringstream ss;
  ss << "{";
  for(auto x: nums){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}
string print(vector<vector<int>>& nums){
  stringstream ss;
  ss << "{";
  for(auto x:nums){
    ss << print(x) << "," << endl;
  }
  ss << "}";
  return ss.str();
}

struct Node{
  int val;
  vector<Node*> children;
  Node(int val): val(val) {}
};
void print(Node* root, int level){
  cout << "Level: " << level << ":" << root->val;
  cout << " Children: {";
  for (auto x : root->children){
    cout << x->val << ",";
  }
  cout << "}" << endl;

  for(auto x : root->children){
    print(x, level+1);
  }
}
void print(Node* root){
    print(root, 0);
}

class Solution{
public:
  void levelOrderTraverse(Node* root, int curLevel, vector<vector<int>>& levelOrderNodes){
    if(!root){
      return;
    }
    if(levelOrderNodes.size() == curLevel){
      vector<int> temp(1, root->val);
      levelOrderNodes.push_back(temp);
    }else{
      levelOrderNodes[curLevel].push_back(root->val);
    }
    vector<Node*>& children = root->children;
    for(auto x:children){
      levelOrderTraverse(x, curLevel+1, levelOrderNodes);
    }
  }
  void printLevelOrder(Node* root){
    vector<vector<int>> levelOrderNodes;
    levelOrderTraverse(root, 0, levelOrderNodes);

    cout << "LevelOrder:" << endl;
    cout << print(levelOrderNodes) << endl;;
  }
};
int main(int argc, char** argv){
  Solution s;
  Node* root = new Node(15);
  Node* a = new Node(2);
  Node* b = new Node(13);
  Node* c = new Node(1);
  Node* d = new Node(1);
  Node* e = new Node(6);
  Node* f = new Node(7);
  Node* g = new Node(3);
  Node* h = new Node(3);
  Node* i = new Node(4);
  Node* j = new Node(3);

  root->children.push_back(a);
  root->children.push_back(b);
  a->children.push_back(c);
  a->children.push_back(d);
  b->children.push_back(e);
  b->children.push_back(f);
  c->children.push_back(g);
  c->children.push_back(h);
  d->children.push_back(i);
  d->children.push_back(j);

  cout << "Tree: " << endl;
  print(root);
  s.printLevelOrder(root);

}
