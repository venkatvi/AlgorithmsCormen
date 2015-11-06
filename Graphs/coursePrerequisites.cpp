#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <iostream>
using namespace std;
struct GraphNode{
    int val;
    std::vector<GraphNode*> prev;
    std::vector<GraphNode*> next;
    GraphNode(int v): val(v){}
};
class Stack{
    public:
        void push(GraphNode* n){
            elements.push_back(n);
        }
        void pop() {
            elements.pop_back();
        }
        GraphNode* top(){
            return elements.back();
        }
        bool isEmpty(){
            return (elements.size() == 0);
        }
        int size() {
            return elements.size();
        }
  private:
    std::vector<GraphNode*> elements;
};
class Solution {
private: 
    void computePrerequisiteGraph(std::map<int, GraphNode*>& allNodes, std::vector<pair<int, int>>& prerequisites){
        for(auto& x:prerequisites){
            GraphNode* successor, *predecessor;
            if(allNodes.find(x.first) == allNodes.end()){
                successor = new GraphNode(x.first);
                allNodes.insert({x.first, successor});
            }else{
                successor = allNodes[x.first];
            }
            if(allNodes.find(x.second) == allNodes.end()){
                predecessor = new GraphNode(x.second);
                allNodes.insert({x.second, predecessor});
            }else{
                predecessor = allNodes[x.second];
                
            }
            std::vector<GraphNode*>& parentNodes = successor->prev;
            if(std::find(parentNodes.begin(), parentNodes.end(), predecessor) == parentNodes.end()){
                parentNodes.push_back(predecessor);
            }
            
            std::vector<GraphNode*>& childNodes = predecessor->next;
            if(std::find(childNodes.begin(), childNodes.end(), successor) == childNodes.end()){
                childNodes.push_back(successor);
            }
        }
    }
    void computeInDegree(std::vector<int>& inDegree, std::map<int, GraphNode*>& allNodes){
        for(auto& x:allNodes){
            int index = x.first;
            inDegree[index] = ((x.second)->prev).size();
        }
    }
    bool isTopoSortable(std::vector<int>& sortOrder, std::vector<int>& inDegree, std::map<int, GraphNode*>& allNodes){
        Stack s;
        int numPushes = 0;
        for(int i=0; i<inDegree.size(); i++){
            if(inDegree[i] == 0){
                if(allNodes.find(i) != allNodes.end()){
                    numPushes++;
                    s.push(allNodes[i]);

                }
            }
        }
        if (s.isEmpty()){
            return false;
        }else{

            while(!s.isEmpty()){
                GraphNode* top = s.top();
                s.pop();
                sortOrder.push_back(top->val);
                inDegree[top->val]--;

                std::vector<GraphNode*> incidentNodes = top->next;
             
                for(int i=0; i < (top->next).size(); i++){
                    GraphNode* x = (top->next)[i];
                    inDegree[x->val]--;
                    if(inDegree[x->val] == 0){
                        s.push(x);
                    }
                }
            }
            for(int i=0; i<inDegree.size();i++){
                if (inDegree[i] > 0){
                    return false;
                }
            }

            return true;
        }
    }
public:
    vector<int> findOrder(int numCourses, std::vector<pair<int, int>>& prerequisites) {
        vector<int> sortOrder;
        if(prerequisites.size() == 0 || numCourses == 0){
            return sortOrder;
        }

        std::map<int, GraphNode*> allNodes;
        computePrerequisiteGraph(allNodes, prerequisites);
        
        std::vector<int> inDegree(numCourses, 0);
        computeInDegree(inDegree, allNodes);
        
        
        bool result = isTopoSortable(sortOrder, inDegree, allNodes);
        for(auto& x: allNodes){
            GraphNode* temp = x.second;
            temp->next.clear();
            temp->prev.clear();
            delete temp;
        }
        if(!result){
            return sortOrder;
        }else{
            sortOrder.clear();
        }
    }
};
int main(int argc, char** argv){
    Solution s;

    std::vector<pair<int,int>> prerequisites = {std::pair<int,int>(1, 0)};
    /*
    bool res = s.canFinish(2, prerequisites);
    cout << "CanFinish: " << res << endl;
    cout << "---------------------------------------------" << endl;

    prerequisites.clear();
    prerequisites.push_back(std::pair<int, int>(1, 0));
    prerequisites.push_back(std::pair<int, int>(0, 1));
    res = s.canFinish(2, prerequisites);
    cout << "CanFinish: " << res << endl;
    cout << "---------------------------------------------" << endl;

    prerequisites.clear();
    prerequisites.push_back(std::pair<int, int>(1, 0));
    prerequisites.push_back(std::pair<int, int>(2, 1));
    prerequisites.push_back(std::pair<int, int>(3, 2));
    res = s.canFinish(5, prerequisites);
    cout << "CanFinish: " << res << endl;
    cout << "---------------------------------------------" << endl;

    prerequisites.clear();
    prerequisites.push_back(std::pair<int, int>(1, 0));
    prerequisites.push_back(std::pair<int, int>(2, 1));
    prerequisites.push_back(std::pair<int, int>(3, 0));
    res = s.canFinish(5, prerequisites);
    cout << "CanFinish: " << res << endl;
    cout << "---------------------------------------------" << endl;

    prerequisites.clear();
    prerequisites.push_back(std::pair<int, int>(1, 0));
    prerequisites.push_back(std::pair<int, int>(2, 1));
    prerequisites.push_back(std::pair<int, int>(3, 3));
    res = s.canFinish(5, prerequisites);
    cout << "CanFinish: " << res << endl;
    cout << "---------------------------------------------" << endl;*/

    
    prerequisites.clear();
    prerequisites.push_back(std::pair<int, int>(6,27));
    prerequisites.push_back(std::pair<int, int>(83,9));
    prerequisites.push_back(std::pair<int, int>(10,95));
    prerequisites.push_back(std::pair<int, int>(48,67));
    prerequisites.push_back(std::pair<int, int>(5,71));
    prerequisites.push_back(std::pair<int, int>(18,72));
    prerequisites.push_back(std::pair<int, int>(7,10));
    prerequisites.push_back(std::pair<int, int>(92,4));
    prerequisites.push_back(std::pair<int, int>(68,84));
    prerequisites.push_back(std::pair<int, int>(6,41));
    prerequisites.push_back(std::pair<int, int>(82,41));
    prerequisites.push_back(std::pair<int, int>(18,54));
    prerequisites.push_back(std::pair<int, int>(0,2));
    prerequisites.push_back(std::pair<int, int>(1,2));
    prerequisites.push_back(std::pair<int, int>(8,65));
    prerequisites.push_back(std::pair<int, int>(47,85));
    prerequisites.push_back(std::pair<int, int>(39,51));
    prerequisites.push_back(std::pair<int, int>(13,78));
    prerequisites.push_back(std::pair<int, int>(77,50));
    prerequisites.push_back(std::pair<int, int>(70,56));
    prerequisites.push_back(std::pair<int, int>(5,61));
    prerequisites.push_back(std::pair<int, int>(26,56));
    prerequisites.push_back(std::pair<int, int>(18,19));
    prerequisites.push_back(std::pair<int, int>(35,49));
    prerequisites.push_back(std::pair<int, int>(79,53));
    prerequisites.push_back(std::pair<int, int>(40,22));
    prerequisites.push_back(std::pair<int, int>(8,19));
    prerequisites.push_back(std::pair<int, int>(60,56));
    prerequisites.push_back(std::pair<int, int>(48,50));
    prerequisites.push_back(std::pair<int, int>(20,70));
    prerequisites.push_back(std::pair<int, int>(35,12));
    prerequisites.push_back(std::pair<int, int>(99,85));
    prerequisites.push_back(std::pair<int, int>(12,75));prerequisites.push_back(std::pair<int, int>(2,36));prerequisites.push_back(std::pair<int, int>(36,22));
    prerequisites.push_back(std::pair<int, int>(21,15));prerequisites.push_back(std::pair<int, int>(98,1));prerequisites.push_back(std::pair<int, int>(34,94));
    prerequisites.push_back(std::pair<int, int>(25,41));prerequisites.push_back(std::pair<int, int>(65,17));prerequisites.push_back(std::pair<int, int>(1,56));
    prerequisites.push_back(std::pair<int, int>(43,96));prerequisites.push_back(std::pair<int, int>(74,57));prerequisites.push_back(std::pair<int, int>(19,62));
    prerequisites.push_back(std::pair<int, int>(62,78));prerequisites.push_back(std::pair<int, int>(50,86));prerequisites.push_back(std::pair<int, int>(46,22));
    prerequisites.push_back(std::pair<int, int>(10,13));prerequisites.push_back(std::pair<int, int>(47,18));prerequisites.push_back(std::pair<int, int>(20,66));
    prerequisites.push_back(std::pair<int, int>(83,66));prerequisites.push_back(std::pair<int, int>(51,47));prerequisites.push_back(std::pair<int, int>(23,66));
    prerequisites.push_back(std::pair<int, int>(87,42));prerequisites.push_back(std::pair<int, int>(25,81));prerequisites.push_back(std::pair<int, int>(60,81));
    prerequisites.push_back(std::pair<int, int>(25,93));prerequisites.push_back(std::pair<int, int>(35,89));prerequisites.push_back(std::pair<int, int>(65,92));
    prerequisites.push_back(std::pair<int, int>(87,39));prerequisites.push_back(std::pair<int, int>(12,43));prerequisites.push_back(std::pair<int, int>(75,73));
    prerequisites.push_back(std::pair<int, int>(28,96));prerequisites.push_back(std::pair<int, int>(47,55));prerequisites.push_back(std::pair<int, int>(18,11));
    prerequisites.push_back(std::pair<int, int>(29,58));prerequisites.push_back(std::pair<int, int>(78,61));prerequisites.push_back(std::pair<int, int>(62,75));
    prerequisites.push_back(std::pair<int, int>(60,77));prerequisites.push_back(std::pair<int, int>(13,46));prerequisites.push_back(std::pair<int, int>(97,92));
    prerequisites.push_back(std::pair<int, int>(4,64));prerequisites.push_back(std::pair<int, int>(91,47));prerequisites.push_back(std::pair<int, int>(58,66));
    prerequisites.push_back(std::pair<int, int>(72,74));prerequisites.push_back(std::pair<int, int>(28,17));prerequisites.push_back(std::pair<int, int>(29,98));
    prerequisites.push_back(std::pair<int, int>(53,66));prerequisites.push_back(std::pair<int, int>(37,5));prerequisites.push_back(std::pair<int, int>(38,12));
    prerequisites.push_back(std::pair<int, int>(44,98));prerequisites.push_back(std::pair<int, int>(24,31));prerequisites.push_back(std::pair<int, int>(68,23));
    prerequisites.push_back(std::pair<int, int>(86,52));prerequisites.push_back(std::pair<int, int>(79,49));prerequisites.push_back(std::pair<int, int>(32,25));
    prerequisites.push_back(std::pair<int, int>(90,18));prerequisites.push_back(std::pair<int, int>(16,57));prerequisites.push_back(std::pair<int, int>(60,74));
    prerequisites.push_back(std::pair<int, int>(81,73));prerequisites.push_back(std::pair<int, int>(26,10));prerequisites.push_back(std::pair<int, int>(54,26));
    prerequisites.push_back(std::pair<int, int>(57,58));prerequisites.push_back(std::pair<int, int>(46,47));prerequisites.push_back(std::pair<int, int>(66,54));
    prerequisites.push_back(std::pair<int, int>(52,25));prerequisites.push_back(std::pair<int, int>(62,91));prerequisites.push_back(std::pair<int, int>(6,72));
    prerequisites.push_back(std::pair<int, int>(81,72));prerequisites.push_back(std::pair<int, int>(50,35));prerequisites.push_back(std::pair<int, int>(59,87));
    prerequisites.push_back(std::pair<int, int>(21,3));prerequisites.push_back(std::pair<int, int>(4,92));prerequisites.push_back(std::pair<int, int>(70,12));
    prerequisites.push_back(std::pair<int, int>(48,4));prerequisites.push_back(std::pair<int, int>(9,23));prerequisites.push_back(std::pair<int, int>(52,55));
    prerequisites.push_back(std::pair<int, int>(43,59));prerequisites.push_back(std::pair<int, int>(49,26));prerequisites.push_back(std::pair<int, int>(25,90));
    prerequisites.push_back(std::pair<int, int>(52,0));prerequisites.push_back(std::pair<int, int>(55,8));prerequisites.push_back(std::pair<int, int>(7,23));
    prerequisites.push_back(std::pair<int, int>(97,41));prerequisites.push_back(std::pair<int, int>(0,40));prerequisites.push_back(std::pair<int, int>(69,47));
    prerequisites.push_back(std::pair<int, int>(73,68));prerequisites.push_back(std::pair<int, int>(10,6));prerequisites.push_back(std::pair<int, int>(47,9));
    prerequisites.push_back(std::pair<int, int>(64,24));prerequisites.push_back(std::pair<int, int>(95,93));prerequisites.push_back(std::pair<int, int>(79,66));
    prerequisites.push_back(std::pair<int, int>(77,21));prerequisites.push_back(std::pair<int, int>(80,69));prerequisites.push_back(std::pair<int, int>(85,5));
    prerequisites.push_back(std::pair<int, int>(24,48));prerequisites.push_back(std::pair<int, int>(74,31));prerequisites.push_back(std::pair<int, int>(80,76));
    prerequisites.push_back(std::pair<int, int>(81,27));prerequisites.push_back(std::pair<int, int>(71,94));prerequisites.push_back(std::pair<int, int>(47,82));
    prerequisites.push_back(std::pair<int, int>(3,24));prerequisites.push_back(std::pair<int, int>(66,61));prerequisites.push_back(std::pair<int, int>(52,13));
    prerequisites.push_back(std::pair<int, int>(18,38));prerequisites.push_back(std::pair<int, int>(1,35));prerequisites.push_back(std::pair<int, int>(32,78));
    prerequisites.push_back(std::pair<int, int>(7,58));prerequisites.push_back(std::pair<int, int>(26,58));prerequisites.push_back(std::pair<int, int>(64,47));
    prerequisites.push_back(std::pair<int, int>(60,6));prerequisites.push_back(std::pair<int, int>(62,5));prerequisites.push_back(std::pair<int, int>(5,22));
    prerequisites.push_back(std::pair<int, int>(60,54));prerequisites.push_back(std::pair<int, int>(49,40));prerequisites.push_back(std::pair<int, int>(11,56));
    prerequisites.push_back(std::pair<int, int>(19,85));prerequisites.push_back(std::pair<int, int>(65,58));prerequisites.push_back(std::pair<int, int>(88,44));
    prerequisites.push_back(std::pair<int, int>(86,58));

    vector<int> res = s.findOrder(100, prerequisites);
    cout << "CanFinish: " << (res.size() > 0) << endl;
    cout << "Linear Order: ";
    for(auto x:res){
        cout << x << ",";
    }
    cout << endl;
    cout << "---------------------------------------------" << endl;
    
}
