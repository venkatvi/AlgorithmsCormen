#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
enum MARK{ UNVISITED=0, VISITED=1, PROCESSED=2};
struct GraphNode{
    int val;
    vector<GraphNode*> prev;
    vector<GraphNode*> next;
    GraphNode(int v): val(v){}
};
class Stack{
    public:
        void push(GraphNode* n){
            elements.push_back(n);
        }
        void pop(){
            elements.pop_back();
        }
        GraphNode* top(){
            return elements.back();
        }
        bool isEmpty(){
            return (elements.size() == 0);
        }
        int size(){
            return elements.size();
        }
    private:
        vector<GraphNode*> elements;
};
class Solution {
private: 
    bool populateStatus(map<GraphNode*, MARK>& status, GraphNode* root, vector<GraphNode*>& path){
        if(status[root] == MARK::UNVISITED){
            path.push_back(root);
            status[root] = MARK::VISITED;
            for(auto& x : root->next){
                if(status.find(x) == status.end()){
                    status.insert({x, MARK::UNVISITED});
                    if(!populateStatus(status, x, path)){
                        return false;
                    }
                    //prepare for the next for loop. 
                }else{
                    //node was already visited via another node. 
                    //check if it was its ancestor
                    if(path[path.size()-2] != x){
                       return false;
                    }
                }
            }
            status[root] = MARK::PROCESSED;
            path.pop_back();
        }
        return true;
    }
    void constructGraph(vector<GraphNode*>& nodes, int n, vector<pair<int, int>>& edges){
        for( int i=0; i<n; i++){
            nodes[i] = new GraphNode(i);
        }
        for(auto& x : edges){
            GraphNode* srcNode = nodes[x.first];
            GraphNode* destNode = nodes[x.second];
            
            vector<GraphNode*>& srcNext = srcNode->next;
            if(std::find(srcNext.begin(), srcNext.end(), destNode) == srcNext.end()){
                (srcNode->next).push_back(destNode);
            }
            vector<GraphNode*>& destNext = destNode->next;
            if(std::find(destNext.begin(), destNext.end(), srcNode) == destNext.end()){
                (destNode->next).push_back(srcNode);
            }
        }
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n == 0 || n == 1) { return true;}
        vector<GraphNode*> nodes(n);
        constructGraph(nodes, n, edges);
        
        //find if tree exists
        map<GraphNode*, MARK> status;
        status.insert({nodes[0], MARK::UNVISITED});
        vector<GraphNode*> path;
        bool res = populateStatus(status, nodes[0], path);
        if(!res || status.size() != n ){
            return false;
        }
        return true;
    }
};
int main(int argc, char** argv){
    Solution s;
    int n = 5;
    vector<pair<int, int>> edges;
    edges.push_back(std::pair<int,int>(0, 1));
    edges.push_back(std::pair<int,int>(0, 2));
    edges.push_back(std::pair<int,int>(0, 3));
    edges.push_back(std::pair<int,int>(1, 4));

    cout << "Test Case 1" << endl;
    bool res = s.validTree(n, edges);
    cout << "IsValidTree: " << res << endl;
    cout << "------------------------------" << endl;

    edges.clear();
    edges.push_back(std::pair<int,int>(0,1));
    edges.push_back(std::pair<int,int>(1,2));
    edges.push_back(std::pair<int,int>(2,3));
    edges.push_back(std::pair<int,int>(1,3));
    edges.push_back(std::pair<int,int>(1,4));

    cout << "Test Case 2" << endl;
    res = s.validTree(n, edges);
    cout << "IsValidTree: " << res << endl;
    cout << "------------------------------" << endl;

    edges.clear();
    edges.push_back(std::pair<int,int>(0,1));
    edges.push_back(std::pair<int,int>(1,2));
    edges.push_back(std::pair<int,int>(3,4));

    cout << "Test Case 3" << endl;
    res = s.validTree(n, edges);
    cout << "IsValidTree: " << res << endl;
    cout << "------------------------------" << endl;

    edges.clear();
    n = 1;
    cout << "Test Case 4" << endl;
    res = s.validTree(n, edges);
    cout << "IsValidTree: " << res << endl;
    cout << "------------------------------" << endl;

    edges.clear();
    n = 0;
    cout << "Test Case 5" << endl;
    res = s.validTree(n, edges);
    cout << "IsValidTree: " << res << endl;
    cout << "------------------------------" << endl;

    edges.clear();
    n = 2;
    edges.push_back(std::pair<int,int>(0,1));
    cout << "Test Case 6" << endl;
    res = s.validTree(n, edges);
    cout << "IsValidTree: " << res << endl;
    cout << "------------------------------" << endl;

    edges.clear();
    edges.push_back(std::pair<int,int>(0,1));
    edges.push_back(std::pair<int,int>(1,2));
    edges.push_back(std::pair<int,int>(2,0));
    n = 3;
    cout << "Test Case 7" << endl;
    res = s.validTree(n, edges);
    cout << "IsValidTree: " << res << endl;
    cout << "------------------------------" << endl;

    edges.clear();
    edges.push_back(std::pair<int,int>(2,3));
    edges.push_back(std::pair<int,int>(1,2));
    edges.push_back(std::pair<int,int>(1,3));
    n = 4;
    cout << "Test Case 8" << endl;
    res = s.validTree(n, edges);
    cout << "IsValidTree: " << res << endl;
    cout << "------------------------------" << endl;


}