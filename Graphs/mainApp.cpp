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

	G.addEdge(aIndex, bIndex, 1);
	G.addEdge(aIndex, cIndex, 2);
	G.addEdge(bIndex, fIndex, 3);
	G.addEdge(cIndex, dIndex, 4);
	G.addEdge(cIndex, eIndex, 1);
	G.addEdge(eIndex, dIndex, 2);
	G.addEdge(dIndex, fIndex, 1);

	//G.print();

	G.topologicalSort();

	Graph<int> clone = G.clone();

	clone.print();
	

	return 0;




}
