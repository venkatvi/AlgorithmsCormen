#include <iostream>
#include "Graph.hpp"
using namespace std;

int main(int argc, char** argv){
	/*Stack<int> intStack;
	intStack.push(3);
	intStack.push(5);
	intStack.push(7);
	intStack.print();
	int top=intStack.pop();
	intStack.print();
	cout << intStack.top() << endl;

	cout << intStack.isEmpty() << endl;

	Stack<int> anotherIntStack = intStack.clone();

	anotherIntStack.print();
	anotherIntStack.pop();
	anotherIntStack.pop();
	anotherIntStack.pop();
	anotherIntStack.top();
	*/
	Graph<int> G;

	int aIndex = G.addNode(1);
	int bIndex = G.addNode(2);
	int cIndex = G.addNode(3);
	int dIndex = G.addNode(4);
	int eIndex = G.addNode(5);
	int fIndex = G.addNode(6);

	G.addEdge(aIndex, bIndex);
	G.addEdge(aIndex, cIndex);
	G.addEdge(bIndex, fIndex);
	G.addEdge(cIndex, dIndex);
	G.addEdge(cIndex, eIndex);
	G.addEdge(eIndex, dIndex);
	G.addEdge(dIndex, fIndex);

	//G.print();

	G.topologicalSort();

	Graph<int> clone = G.clone();

	clone.print();
	

	return 0;




}
