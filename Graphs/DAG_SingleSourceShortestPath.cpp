#include "Graph.hpp"
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

    shortestPath[pNodeIndex] = 0;
    
    for (auto& x: sortedNodeIndices){
        shortestPath.insert(std::pair<int,int>(x, INT_MAX));
        previousNodeIndex.insert(std::pair<int,int>(x, -1));
        
        if (x == pNodeIndex){
            shortestPath[pNodeIndex] = 0;
            
        }
       
		const EdgeInfo& edges = G.getEdges(x);
		for (auto& y: edges){
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
    
    cout << "Printing distances.. " << endl;
    for (auto& x : shortestPath){
        cout << x.first << "-" << x.second << endl;
    }
    cout << "Printing previous nodes... " << endl;
    for (auto& x: previousNodeIndex){
        cout << x.first << "-" << x.second << endl;
    }
};
