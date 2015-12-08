#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "Graph.hpp"
template<typename T>
void findSingleSourceShortestPath(Graph<T>& G, const int pNodeIndex);

template<typename T>
void dijkstras(Graph<T>& G, const int pNodeIndex);

template<typename T>
void bellmanFord(Graph<T>& G, const int pNodeIndex);

template<typename T>
void floydWarshall(Graph<T>& G);
#endif
