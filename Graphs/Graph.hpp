#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include "Node.hpp"
typedef std::vector<std::pair<int,int>> EdgeInfo;
typedef std::pair<int,int> Edge;

template<typename T>
class Graph{
	public:
		Graph(){}
		~Graph(){}
		int addNode(const T pVal);
		void addEdge(const int mNodeIndex1, const int mNodeIndex2, const int weight);
		std::vector<int>& topologicalSort();
		Graph clone() const;
		void print() const;
	private: 
		std::vector<int> getIndegree() const;
		const EdgeInfo& getEdges(int srcIndex);
		bool isKey(int srcIndex);
		
		std::vector<Node<T>> mNodes;	
		std::map<int, EdgeInfo> mAdjacencyList;
};
#endif
