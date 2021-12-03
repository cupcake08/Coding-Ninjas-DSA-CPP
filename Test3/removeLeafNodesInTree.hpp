/*

Remove all leaf nodes from a given generic Tree. Leaf nodes are those nodes, which don't have any children.
Note : 
    Root will also be a leaf node if it doesn't have any child. You don't need to print the tree, just remove all leaf nodes and return the updated root.

Sample Input 1 :
    10 3 20 30 40 2 40 50 0 0 0 0 
    
Sample Output 1 : (Level wise, each level in new line)
10
20

*/

#define tn TreeNode<int>*

tn removeLeafNodes(tn root){	
    if(root == NULL || root->numChildren()==0) return NULL;
    for(int i=0;i<root->numChildren();i++){
        tn child = root->getChild(i);
        if(child->numChildren()==0){
            root->removeChild(i);
            i--;
        }
    }
    for(int i=0;i<root->numChildren();i++){
        tn temp = removeLeafNodes(root->getChild(i));
        if(temp == NULL) root->removeChild(i);
    }
    return root;
}
