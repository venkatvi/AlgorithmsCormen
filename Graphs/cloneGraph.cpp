#include <iostream>
#include <map>
#include <vector>
using namespace std;
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 struct UndirectedGraphNode{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x):label(x) {};
 };
enum MARKNODE{ UNVISITED=0, VISITED=1, PROCESSED=2};
class Solution {
private:
    void createNodeCloneMap(map<UndirectedGraphNode*,UndirectedGraphNode*>& nodeMap, map<UndirectedGraphNode*, MARKNODE>& status, UndirectedGraphNode* node){
        if(!node) { return; }
        if (status.find(node) != status.end()){
            if(status[node] == MARKNODE::UNVISITED){
                status[node] = MARKNODE::VISITED;
                UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
                nodeMap.insert({node, clone});
                for(auto& x:node->neighbors){
                    if(status.find(x) == status.end()){
                        status.insert({x, MARKNODE::UNVISITED});
                        createNodeCloneMap(nodeMap, status, x);
                    }
                }
                status[node] = MARKNODE::PROCESSED;
                return;
            }
        }
        return;
    }
    void cloneNodeWise(map<UndirectedGraphNode*, UndirectedGraphNode*>& nodeMap){
        for(auto& x: nodeMap){
            UndirectedGraphNode* originalNode = x.first;
            UndirectedGraphNode* clonedNode = x.second;
            vector<UndirectedGraphNode*>& clonedNeighbors = clonedNode->neighbors;
            for(auto& y: originalNode->neighbors){
                UndirectedGraphNode* newNeighbor = nodeMap[y];
                clonedNeighbors.push_back(newNeighbor);
            }
        }
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode*, MARKNODE> status;
        map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        
        status.insert({node, MARKNODE::UNVISITED});
        createNodeCloneMap(nodeMap, status, node);
        cloneNodeWise(nodeMap);
        return nodeMap[node];
    }
};
void printGraph(map<UndirectedGraphNode*, MARKNODE>& status, UndirectedGraphNode* root){
    if(root && status[root] == MARKNODE::UNVISITED){
        status[root] = MARKNODE::VISITED;
        cout << "Node: " << root->label << endl;
        cout << "Neighbors: ";
        for(auto& x:root->neighbors){
            if (status.find(x) == status.end()){
                status.insert({x, MARKNODE::UNVISITED});
            }
            cout << x->label << "," ;
        }
        cout << endl;
        cout << "------------------" << endl;

        for(auto& x:root->neighbors){
            printGraph(status, x);
        }
    }else{
        return;
    }
}
int main(int argc, char** argv){
    UndirectedGraphNode* G = new UndirectedGraphNode(1);
    UndirectedGraphNode* b = new UndirectedGraphNode(2);
    UndirectedGraphNode* c = new UndirectedGraphNode(3);
    UndirectedGraphNode* d = new UndirectedGraphNode(4);
    vector<UndirectedGraphNode*>& Gneighbors = G->neighbors;
    Gneighbors.push_back(b);
    Gneighbors.push_back(c);
    vector<UndirectedGraphNode*>& bneighbors = b->neighbors;
    bneighbors.push_back(b);
    bneighbors.push_back(c);
    vector<UndirectedGraphNode*>& cneighbors = c->neighbors;
    cneighbors.push_back(G);
    cneighbors.push_back(b);
    cneighbors.push_back(d);
    vector<UndirectedGraphNode*>& dneighbors = d->neighbors;
    cneighbors.push_back(c);
    
    Solution s;
    UndirectedGraphNode* clone = s.cloneGraph(G);

    map<UndirectedGraphNode*, MARKNODE> status;
    status.insert({clone, MARKNODE::UNVISITED});
    printGraph(status, clone);
}