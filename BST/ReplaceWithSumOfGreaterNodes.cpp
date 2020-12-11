int replace(BinaryTreeNode<int> *root,int sum)
{
    //right call
    if(root==nullptr)
    {
        return sum;
    }
    sum=replace(root->right,sum);
    sum+=root->data;
    root->data=sum;
    sum=replace(root->left,sum);
    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    replace(root,0);
}
