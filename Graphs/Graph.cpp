#include "Graph.hpp"
#include "Node.hpp"
#include "Stack.hpp"

#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
int Graph<T>::addNode(const T pVal){
	Node<T> pNode(pVal);
	mNodes.push_back(pNode);
	return mNodes.size()-1;
}


struct EdgeComparator{
	public:
		EdgeComparator(const int pVal): mVal(pVal){}
 		bool operator()(const Edge& pEdge){
			return pEdge.first == mVal;
		}
	private:
		int mVal;
};

template<typename T>
void Graph<T>::addEdge(const int mNodeIndex1, const int mNodeIndex2, const int weight){
	if (mAdjacencyList.find(mNodeIndex1) != mAdjacencyList.end()){
		EdgeInfo& edgeInfo =	mAdjacencyList.find(mNodeIndex1)->second;
		if(std::find_if(edgeInfo.begin(), edgeInfo.end(), EdgeComparator(mNodeIndex2)) == edgeInfo.end()) {
			edgeInfo.push_back(Edge(mNodeIndex2, weight));

		}
	}else{
		EdgeInfo edgeInfo;
		edgeInfo.push_back(Edge(mNodeIndex2, weight));
		mAdjacencyList.insert(std::pair<int, EdgeInfo>(mNodeIndex1, edgeInfo));
	}
} 

template<typename T>
std::vector<int> Graph<T>::topologicalSort(){
	Stack<int> nextIndices;
	std::vector<int> nodeInDegree = getIndegree();
	for(auto i=0; i<nodeInDegree.size(); i++){
		if(nodeInDegree[i] == 0){
			nextIndices.push(i);	
		}
	}
	std::vector<int> linearOrder;
	while(!nextIndices.isEmpty()){
		int top = nextIndices.pop();
		linearOrder.push_back(top);
		
		if (isKey(top)){
			EdgeInfo edgeInfo;
			bool success = getEdges(edgeInfo, top);
			if (success){
				for(auto i=0; i< edgeInfo.size(); i++){
					nodeInDegree[edgeInfo[i].first]--;
					if(nodeInDegree[edgeInfo[i].first] == 0){
						nextIndices.push(edgeInfo[i].first);
					}
				}
			}
		}
	}
	return linearOrder;
}	

template<typename T>
Graph<T> Graph<T>::clone() const {
	Graph<T> graphClone; 
	
	for(auto& x: mNodes){
		int nodeId = graphClone.addNode(x.getVal());
	}
	for (auto& x: mAdjacencyList){
		auto nodeId = x.first;	
		auto edgeVector = x.second;

		for(auto& y: edgeVector){
			graphClone.addEdge(nodeId, y.first, y.second);
		}
	}
	return graphClone;
}

template<typename T>
void Graph<T>::print() const {
	cout << "Printing graph ... " << endl;
	for(auto& x:mAdjacencyList){
		cout << "Key: " << x.first << " Values: ";
		const EdgeInfo& edges = x.second;
		for(auto y: edges){
			cout << y.first  << ",";
		}
		cout << endl;
	}
}

template<typename T>
std::vector<int> Graph<T>::getIndegree() const{
	std::vector<int> inDegree(mNodes.size(), 0);
	for(auto i=0; i<mNodes.size(); ++i){
		if (mAdjacencyList.find(i) != mAdjacencyList.end()){
			const EdgeInfo& edges = mAdjacencyList.find(i)->second;
			for(auto x: edges){
				inDegree[x.first]++;
			}
		}
	}
	return inDegree;
}

template<typename T>
bool Graph<T>::getEdges(EdgeInfo& edgeInfo, const int srcIndex){
	if(mAdjacencyList.find(srcIndex) != mAdjacencyList.end()){
		edgeInfo  = mAdjacencyList.find(srcIndex)->second;
		return true;
	}else{
		return false;	
	}
}

template<typename T>
std::vector<Node<T>> Graph<T>::getNodes() const{
	return mNodes;
}
template<typename T>
bool Graph<T>::isKey(int srcIndex){
	return (mAdjacencyList.find(srcIndex) != mAdjacencyList.end());
}

template<typename T>
bool Graph<T>::getAllEdges(std::map<int, EdgeInfo>& edges){
	edges = mAdjacencyList;
	return true;
}
template class Graph<int>;

