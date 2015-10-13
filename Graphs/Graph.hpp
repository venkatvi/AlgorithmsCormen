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
		int addNode(const T);
		void addEdge(const int, const int, const int);
		std::vector<int> topologicalSort();
		Graph clone() const;
		void print() const;

		std::vector<Node<T>> getNodes() const;
		bool getEdges(EdgeInfo&, const int);
		bool getAllEdges(std::map<int, EdgeInfo>&);
	private: 
		std::vector<int> getIndegree() const;
		bool isKey(int);
		
		std::vector<Node<T>> mNodes;	
		std::map<int, EdgeInfo> mAdjacencyList;
};
#endif
