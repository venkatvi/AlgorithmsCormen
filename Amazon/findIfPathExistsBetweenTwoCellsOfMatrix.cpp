class Node{
	int val;
	Node(int v): val(v);
};
enum MARKNODE{
	UNVISITED=0,
	VISITED=1,
	PROCESSED=2
};
class Graph{
public:
	bool findIfPathsExists(Node* a, Node* b){
		map<Node*, MARKNODE> visitInfo; 
		//Idea: start with a, get all its neighbours, check if any of them is b
		// If yes - return true, If false, for each of neighbours, do the same . 
		if(adjacencyInfo.find(a) == adjacencyInfo.end()){
			return false;
		}

		vector<Node*> neighbours = adjacencyInfo[a];
		if(neighbours.size() == 0){
			return false;
		}
		for(auto x: neighbours){
			if (x == b){
				return true;
			}
		}
		for(auto x: neighbours){
			if(findIfPathsExists(x, b)){
				return true;
			}
		}
		return false;

	}
	Node* addNode(int val){
		nodes.push_back(new Node(val));
		return nodes.back();
	}
	void addEdge(Node* a, Node* b){
		if(adjacencyInfo.find(a) == adjacencyInfo.end()){
			vector<Node*> nextVector(1, b);
			adjacencyInfo.insert({a, nextVector});
		}else{
			vector<Node*>& nextNodes = adjacencyInfo[a];
			if(find(nextNodes.begin(), nextNodes.end(), b) == nextNodes.end()){
				nextNodes.push_back(b);
			}
		}
	}
private:
	vector<Node*> nodes;
	map<Node*, vector<Node*>> adjacencyInfo;
};
bool findIfPathExists(int[][] matrix, int m, int n, int point1, int point2){
	int k = 0; Node* src, *dest;
	
	map<int, Nodes*> nodes; 
	Graph G;
	for(int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if(matrix[i][j] == 1){
				Node* a = G.addNode(k);
				nodes.insert({k, a});
				if (k == point1){
					src = a;
				}
				if(k == point2){
					dest = a;
				}
			}
			k++;
		}
	}
	int k = 0;
	for(int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			Node* a = nodes[k];
			if(matrix[i][j] == 1){
				// 8 positions around i,j 
				// [i-1, j-1], [i-1, j], [i-1, j+1], [i, j-1], [i, j+1], [i+1, j-1], [i+1, j], [i+1, j-1]
				
			}
			k++;				
		}
	}
	
}