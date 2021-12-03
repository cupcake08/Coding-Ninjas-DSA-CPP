/*
You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1
Sample Output 1:
9
6
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3
Sample Output 2:
4
5
*/
#define _BTN_ BinaryTreeNode<int>*

void printer(_BTN_ root,int k){
    if(root){
        if(k==0){
            printf("%d\n",root->data);
            return;
        }
        printer(root->left,k-1);
        printer(root->right,k-1);
    }
}
int helper(_BTN_ root,int node,int k){
    if(!root) return -1;
    if(root->data == node){
        printer(root,k);
        return 0;
    }
    int leftDistance = helper(root->left,node,k);
    if(leftDistance != -1){
        if(leftDistance + 1 == k){printf("%d\n",root->data);} else{ printer(root->right,k-leftDistance-2);};
        return 1+leftDistance;
    }
    int rightDistance = helper(root->right,node,k);
    if(rightDistance != -1){
        if(rightDistance + 1 == k){printf("%d\n",root->data);} else {printer(root->left,k-rightDistance-2);};
        return 1 + rightDistance;
    }
    return -1;
}

void nodesAtDistanceK(_BTN_ root, int node, int k) {
    helper(root,node,k);
}
