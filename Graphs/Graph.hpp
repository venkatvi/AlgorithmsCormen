#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include "Node.hpp"

template<typename T>
class Graph{
	public:
		Graph(){}
		~Graph(){}
		int addNode(T pVal);
		void addEdge(int mNodeIndex1, int mNodeIndex2);
		void topologicalSort();
		Graph clone() const;
		void print() const;
	private: 
		std::vector<int> getIndegree() const;
		const std::vector<int>& getAdjacentIndices(int srcIndex);
		bool isKey(int srcIndex);
		
		std::vector<Node<T>> mNodes;	
		std::map<int, std::vector<int>> mAdjacencyList;
};
#endif
