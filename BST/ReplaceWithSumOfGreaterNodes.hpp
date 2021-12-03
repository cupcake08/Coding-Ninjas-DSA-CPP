
#define _BTN_ BinaryTreeNode<int>*
/*
int replace(_BTN_ root,int sum){
    if(!root) return sum;
    sum = replace(root->right,sum);
    sum += root->data;
    root->data = sum;
    sum = replace(root->left,sum);
}

void replaceWithLargerNodesSum(_BTN_ root){
    replace(root,0);
}
*/

int _sum_(_BTN_ root){
    if(!root) return 0;
    return root->data + _sum_(root->left) + _sum_(root->right);
}
void replaceWithLargerNodesSum(_BTN_ root,int sum=0) {
    if(!root) return;
    int rsum = _sum_(root->right);
    root->data += rsum + sum;
    replaceWithLargerNodesSum(root->right,sum);
    sum = root->data;
    replaceWithLargerNodesSum(root->left,sum);
}
