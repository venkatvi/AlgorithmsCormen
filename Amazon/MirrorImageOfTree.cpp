// 1
// 2 3
// 4 5 # 6

//Output
// 1
// 3 2
// 6 # 5 4

struct node {
    int val;
    sturct node *left;
    struct node *right;
}

void mirrorImage(node *newroot) {
    //Idea: 
    // left and right trees are interchanged, recursively till the last leaf node
    //Time: O(n), Space: O(1)
    if(!newroot) { newroot = NULL;  return; }
    if(!newroot->left && !newroot->right) { return; }
    
    node* temp = newroot->right;
    newroot->right = newroot->left;
    newroot->left = temp;
    
    //recursively for left and right subtrees
    mirrorImage(newroot->left, newroot->left);
    mirrorImage(newroot->right, newroot->right);
    return; 
}
//testcases:
// {}
// {1}

// 1
// 3 2
// 6 # 5 4

//
// 1
// 2 #
// 3 # # #

// 1
// # 2
//# # # 3