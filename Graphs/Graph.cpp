#include "Graph.hpp"
#include "Node.hpp"
#include "Stack.hpp"

#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
int Graph<T>::addNode(T pVal){
	Node<T> pNode(pVal);
	mNodes.push_back(pNode);
	return mNodes.size()-1;
}

template<typename T>
void Graph<T>::addEdge(int mNodeIndex1, int mNodeIndex2){
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

template<typename T>
void Graph<T>::topologicalSort(){
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

template<typename T>
Graph<T> Graph<T>::clone() const {
	Graph<T> graphClone; 
	
	for(auto& x: mNodes){
		int nodeId = graphClone.addNode(x.getVal());
	}
	for (auto& x: mAdjacencyList){
		auto nodeId = x.first;	
		auto adjacentNodeVector = x.second;

		for(auto& y: adjacentNodeVector){
			graphClone.addEdge(nodeId, y);
		}
	}
	return graphClone;
}
template<typename T>
void Graph<T>::print() const {
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

template<typename T>
std::vector<int> Graph<T>::getIndegree() const{
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

template<typename T>
const std::vector<int>& Graph<T>::getAdjacentIndices(int srcIndex){
	if(mAdjacencyList.find(srcIndex) != mAdjacencyList.end()){
		const std::vector<int>&	adjacentIndices  = mAdjacencyList.find(srcIndex)->second;
		return adjacentIndices;
	}
}
template<typename T>
bool Graph<T>::isKey(int srcIndex){
	return (mAdjacencyList.find(srcIndex) != mAdjacencyList.end());
}


template class Graph<int>;

