#ifndef GRAPH_H
#define GRAPH_H
#include <algorithm>
#include <vector>
#include <map>
#include "Stack.hpp"
#include "Node.hpp"
#include <iostream>
using namespace std;
template<typename T>
class Graph{
	public:
		Graph(){}
		~Graph(){}
		int addNode(T pVal){
			Node<T> pNode(pVal);
			mNodes.push_back(pNode);
			return mNodes.size()-1;
		}
		void addEdge(int mNodeIndex1, int mNodeIndex2){
			if (mAdjacencyList.find(mNodeIndex1) != mAdjacencyList.end()){
				std::vector<int>& adjacentNodeIndices =	mAdjacencyList.find(mNodeIndex1)->second;
				if(std::find(adjacentNodeIndices.begin(), adjacentNodeIndices.end(), mNodeIndex2) == adjacentNodeIndices.end()) {
				adjacentNodeIndices.push_back(mNodeIndex2);
				
				}
			}else{
				std::vector<int> adjacentNodeIndices;
				adjacentNodeIndices.push_back(mNodeIndex2);
				mAdjacencyList.insert(std::pair<int, std::vector<int>>(mNodeIndex1, adjacentNodeIndices));
			}
		} 
		void topologicalSort(){
			Stack<int> nextIndices;
			std::vector<int> nodeInDegree = getIndegree();
			for(auto i=0; i<nodeInDegree.size(); i++){
				if(nodeInDegree[i] == 0){
					nextIndices.push(i);	
				}
			}
			cout << "Printing topological order... " << endl;
			while(!nextIndices.isEmpty()){
				int top = nextIndices.pop();
				cout << top << endl;
				
				if (isKey(top)){
					const std::vector<int>& adjacentIndices  = getAdjacentIndices(top);
					for(auto i=0; i< adjacentIndices.size(); i++){
						nodeInDegree[adjacentIndices[i]]--;
						if(nodeInDegree[adjacentIndices[i]] == 0){
							nextIndices.push(adjacentIndices[i]);
						}
					}
				}
			}
		}	
		void print() const {
			cout << "Printing graph ... " << endl;
			for(auto& x:mAdjacencyList){
				cout << "Key: " << x.first << " Values: ";
				const std::vector<int>& adjacentIndices = x.second;
				for(auto y: adjacentIndices){
					cout << y  << ",";
				}
				cout << endl;
			}
		}
	private: 
		std::vector<int> getIndegree() const{
			std::vector<int> inDegree(mNodes.size(), 0);
			for(auto i=0; i<mNodes.size(); ++i){
				if (mAdjacencyList.find(i) != mAdjacencyList.end()){
					const std::vector<int>& incidentNodes = mAdjacencyList.find(i)->second;
					for(auto x: incidentNodes){
						inDegree[x]++;
					}
				}
			}
			return inDegree;
		}
		const std::vector<int>& getAdjacentIndices(int srcIndex){
			if(mAdjacencyList.find(srcIndex) != mAdjacencyList.end()){
				const std::vector<int>&	adjacentIndices  = mAdjacencyList.find(srcIndex)->second;
				return adjacentIndices;
			}
		}
		bool isKey(int srcIndex){
			return (mAdjacencyList.find(srcIndex) != mAdjacencyList.end());
		}
		std::vector<Node<T>> mNodes;	
		std::map<int, std::vector<int>> mAdjacencyList;
};
#endif
