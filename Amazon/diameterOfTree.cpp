// 1
// 2 3
// 4 5 # 6
// # # 7 8 # # # 9
// # # # # # # # # # # # # # # 10 11
// 10 has 12 and 13 as children
struct node{
    int val;
    node* left;
    node* right;
};
void findRootToLeafPath(vector<vector<node*>>& rootToLeafPaths, node* root){
}
int diameter(struct node *root) {
    //Idea: for every pair of leafs, find LCA, 
    // Calculate the distance of each of the nodes in the pair from LCA
    // Sum it up as path length for the pair
    // Diameter = max(path lengths of every pair of leaves in the tree)
    // 
    // 1. Root- leaf path of every leaf - O(n)
    // 2. LCA (two leaves) = common node from the leafs to root in the path we got from (1) - O(n^2)
    // 3. #steps it took to reach from leaf to LCA = sum = path length between two leafs - 
    // Time: O(n^2) Space: O(n) paths 
    
    vector<vector<node*>> rootToLeafPaths;
    findRootToLeafPath(rootToLeafPaths, root);
    int maxPathLength = 0;
    for(int i=0; i<rootToLeafPaths.size(); i++){
        vector<node*> rtlA = rootToLeafPaths[i];
        for(int j=i+1; j<rootToLeafPaths.size(); j++){
            vector<node*> rtlB = rootToLeafPaths[j];
            int smallerLength = (rtlA.size() > rtlB.size()) ? rtlA.size(): rtlB.size(); 
            int k=0;
            while(k < smallerLength ){
                if(rtlA[k] == rtlB[k]){
                    k++;
                }
                else{
                    break;
                }
            }
            //prev points to LCA.
            // k - no. of nodes from root;
            //path from leafnodeA to LCA = 
            int nA = rtlA.size() - k ;
            int nB = rtlB.size() - k ;
            int pathLength = nA + nB - 1; 
            if( maxPathLength < pathLength){
                maxPathLength = pathLength;
            }
        }
    }
    return maxPathLength;
}
//corner cases.
{}
{1}


