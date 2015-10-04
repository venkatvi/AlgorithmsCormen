#include "ShortestPathAlgorithms.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <limits.h>
using namespace std;

template<typename T>
void findSingleSourceShortestPath(Graph<T>& G, const int pNodeIndex){
	std::vector<int> sortedNodeIndices = G.topologicalSort();	
	std::map<int, int> shortestPath;
	std::map<int, int> previousNodeIndex;

	for (auto& x: sortedNodeIndices){
		cout << "SortedNodeIndex: " << x << endl;
		shortestPath.insert(std::pair<int,int>(x, INT_MAX));
		previousNodeIndex.insert(std::pair<int,int>(x, -1));
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
};
template void findSingleSourceShortestPath<int>(Graph<int>&, const int);
