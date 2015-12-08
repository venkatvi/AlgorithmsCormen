#include "ShortestPathAlgorithms.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <limits.h>
#include <algorithm>
//#include <boost/range/irange.hpp>
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
		shortestPath.insert({x, INT_MAX});
		previousNodeIndex.insert({x, -1});
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

template<	typename T>
void bellmanFord(Graph<T>& G, const int pNodeIndex){
	std::vector<Node<T>> nodes = G.getNodes(); 
	std::map<int, int> shortestPath;
	std::map<int, int> previousNodeIndex;

	for(auto x: nodes){
		if (x.getVal() == pNodeIndex){
			shortestPath.insert(ShortestPath(pNodeIndex,0));
		}
		else{
			shortestPath.insert(ShortestPath(x.getVal(), INT_MAX));
		}
		previousNodeIndex.insert(PrevNodeInfo(x.getVal(), -1));
	}
	
	std::map<int, EdgeInfo> edges;
	bool ret = G.getAllEdges(edges);
	for(int i=0; i<nodes.size(); i++){
		for(auto x:edges){
			const int srcNodeIndex = x.first;
			const EdgeInfo& destNodesInfo = x.second;
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
template<typename T>
void floydWarshall(Graph<T>& G){
	std::vector<Node<T>> nodes = G.getNodes();
	int n = nodes.size();
	long long shortestPaths[n][n][n+1];
	int prev[n][n][n+1];

	for (int x=0; x<n+1; x++){
		for (int u=0; u<n; u++){
			for (int v=0; v<n; v++){
				shortestPaths[u][v][x] = INT_MAX;
				prev[u][v][x] = -1;
			}
		}
	}

	//update all pairs of paths of length 0 with corresponding edge weights. 
	//update all predecessors as src nodes.
	std::map<int, EdgeInfo> edges;
	bool ret = G.getAllEdges(edges); 

	for(auto x:edges){
		const int srcNodeIndex = x.first;
		const EdgeInfo& destNodesInfo = x.second;
		for (auto y:destNodesInfo){
			const int destNodeIndex = y.first;
			const int edgeWeight = y.second;

			shortestPaths[srcNodeIndex][destNodeIndex][0] = edgeWeight;
			prev[srcNodeIndex][destNodeIndex][0] = srcNodeIndex-1;

		}
	}
	
	//update shortestPaths by memoizing the shortestpath with different number of intermediate nodes.
	for (int x=1; x<n+1; x++){
		for (int u=0; u<n; u++){
			for (int v=0; v<n; v++){
				long long  shortestPathInvolvingX = shortestPaths[u][x][x-1] + shortestPaths[x][v][x-1]; 
				if (shortestPathInvolvingX < shortestPaths[u][v][x-1]){
					shortestPaths[u][v][x] = shortestPathInvolvingX;
					prev[u][v][x] = prev[x][v][x-1];
				}else{
					shortestPaths[u][v][x] = shortestPaths[u][v][x-1];
					prev[u][v][x] = prev[u][v][x-1];
				}
			}
		}
	}
	for (auto x: edges){
		const int srcNodeIndex = x.first;
		const EdgeInfo& destNodeInfo = x.second;
		cout << "Shortest Paths from node " << srcNodeIndex << endl;

		for(auto y:destNodeInfo){
			const int destNodeIndex = y.first;
			const int edgeWeight = y.second;

			cout << "to node " << destNodeIndex << " : " << shortestPaths[srcNodeIndex][destNodeIndex][nodes.size()-1] << endl;

		}
	}
}

template void findSingleSourceShortestPath<int>(Graph<int>&, const int);
template void dijkstras<int>(Graph<int>&, const int);
template void bellmanFord<int>(Graph<int>&, const int);
template void floydWarshall<int>(Graph<int>&);
