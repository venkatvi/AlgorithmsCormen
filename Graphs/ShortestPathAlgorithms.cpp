#include "ShortestPathAlgorithms.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

typedef std::pair<int, int> ShortestPath;
typedef std::pair<int, int> PrevNodeInfo;

template<typename T>
void findSingleSourceShortestPath(Graph<T>& G, const int pNodeIndex){
	std::vector<int> sortedNodeIndices = G.topologicalSort();	
	std::map<int, int> shortestPath;
	std::map<int, int> previousNodeIndex;

	for (auto& x: sortedNodeIndices){
		cout << "SortedNodeIndex: " << x << endl;
		shortestPath.insert(ShortestPath(x, INT_MAX));
		previousNodeIndex.insert(PrevNodeInfo(x, -1));
	}
	for(auto& x: sortedNodeIndices){
		if (x == pNodeIndex){
			shortestPath[pNodeIndex] = 0;
		}

		EdgeInfo edgeInfo;
		bool success = G.getEdges(edgeInfo, x);
		if(success){
			for (auto& y: edgeInfo){
				const Edge& edge = y;
				const int nodeIndex = y.first;
				const int edgeWeight = y.second;

				//relax edge
				if (shortestPath[nodeIndex] > shortestPath[x] + edgeWeight){
					shortestPath[nodeIndex] = shortestPath[x] + edgeWeight;
					previousNodeIndex[nodeIndex] = x;
				}
			}
		}
	}

	cout << "Printing distances.. " << endl;
	for (auto& x : shortestPath){
		cout << x.first << "-" << x.second << endl;
	}
	cout << "Printing previous nodes... " << endl;
	for (auto& x: previousNodeIndex){
		cout << x.first << "-" << x.second << endl;
	}
}
struct MyComparator{
	private:
		std::map<int, int> sp;
	
	public:
		MyComparator(std::map<int, int>& p): sp(p) {}
		bool operator()(const int& left, const int& right){
			return sp[left] < sp[right];
		}
};

template<typename T>
void dijkstras(Graph<T>& G, const int pNodeIndex){
	std::vector<Node<T>> mNodes = G.getNodes();
	std::vector<int> nodeIndices;
	std::map<int, int> shortestPath;
	std::map<int, int> previousNodeIndex;

	for(auto& x: mNodes){
		nodeIndices.push_back(x.getVal()-1);
		if (x.getVal()-1 == pNodeIndex){
			shortestPath.insert(ShortestPath(pNodeIndex,0));
		}else{
			shortestPath.insert(ShortestPath(x.getVal()-1, INT_MAX));
		}
		previousNodeIndex.insert(PrevNodeInfo(x.getVal()-1, -1));
	}
	while(nodeIndices.size() > 0){
		int nodeIndexToRemove = *min_element(nodeIndices.begin(), nodeIndices.end(), MyComparator(shortestPath));
		auto itPos = std::find(nodeIndices.begin(), nodeIndices.end(), nodeIndexToRemove);
		if (itPos != nodeIndices.end()){
			nodeIndices.erase(itPos);
			EdgeInfo edges;
			bool success = G.getEdges(edges, nodeIndexToRemove);
			if(success){
				for(auto& y: edges){
					int nodeIndex = y.first;
					int weight = y.second;
					if (shortestPath[nodeIndex] > shortestPath[nodeIndexToRemove] + weight){
						shortestPath[nodeIndex] = shortestPath[nodeIndexToRemove] + weight;
						previousNodeIndex[nodeIndex] = nodeIndexToRemove;
					}
				}
			}
		}
	}
	cout << "Printing distances.. " << endl;
	for (auto& x : shortestPath){
		cout << x.first << "-" << x.second << endl;
	}
	cout << "Printing previous nodes... " << endl;
	for (auto& x: previousNodeIndex){
		cout << x.first << "-" << x.second << endl;
	}

	
}

template<typename T>
void bellmanFord(Graph<T>& G, const int pNodeIndex){
	std::vector<Node<T>>& nodes = G.getNodes(); 
	std::map<int, int> shortestPath;
	std::map<int, int> previousNodeIndex;

	for(auto x: nodes){
		if (x.getVal() == pNodeIndex){
			shortestPath.insert(ShortestPath(pNodeIndex,0));
		}
		else{
			shortestPath.insert(ShortestPath(x, INT_MAX));
		}
		previousNodeIndex.insert(PrevNodeInfo(x, -1));
	}
	
	std::map<int, EdgeInfo> edges;
	bool ret = G.getAllEdges(edges);
	for(int i=0; i<nodes.size(); i++){
		for(auto x:edges){
			const int srcNodeIndex = edges.first;
			const EdgeInfo& destNodesInfo = edges.second;
			for (auto y:destNodesInfo){
				const int destNodeIndex = y.first;
				const int edgeWeight = y.second;
				if(shortestPath[destNodeIndex] > shortestPath[srcNodeIndex] + edgeWeight){
					shortestPath[destNodeIndex] = shortestPath[srcNodeIndex] + edgeWeight;
					previousNodeIndex[destNodeIndex] = srcNodeIndex;
				}
			}
		}
			
	}
	cout << "Printing distances.. " << endl;
	for (auto& x : shortestPath){
		cout << x.first << "-" << x.second << endl;
	}
	cout << "Printing previous nodes... " << endl;
	for (auto& x: previousNodeIndex){
		cout << x.first << "-" << x.second << endl;
	}
	
}

template void findSingleSourceShortestPath<int>(Graph<int>&, const int);
template void dijkstras<int>(Graph<int>&, const int);
template void bellmanFord<int>(Graph<int>&, const int);

