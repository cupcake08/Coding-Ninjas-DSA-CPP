/*

Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. 
Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.

(Do it in O(n)).
Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4

Sample Output :
true

*/

#define _VI_ vector<int>
#define _BTN_ BinaryTreeNode<int>*

const int N = 1e5+5;

_VI_ v(N,-1);
bool isSiblingAndHelper(_BTN_ root,int level,int p,int q){
    if(root == NULL) return 0;
    if(root->left && root->left->data == p && root->right && root->right->data == q) return 1;
    if(root->left && root->left->data == q && root->right && root->right->data == p) return 1;
    v[root->data]=level;
    return isSiblingAndHelper(root->left,level+1,p,q) || isSiblingAndHelper(root->right,level+1,p,q);
}

bool isCousin(_BTN_ root, int p, int q) {
    if(root == NULL) return 0;
    if(root->data == p || root->data == q) return 0;
    if(!isSiblingAndHelper(root,0,p,q)) return v[p]==v[q];
    else return 0;
}
