BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root)
{
    if(root==nullptr) return NULL;
    if(root->left==nullptr&&root->right==nullptr) return NULL;
    BinaryTreeNode<int> *node1=removeLeafNodes(root->left);
    BinaryTreeNode<int> *node2=removeLeafNodes(root->right);
    root->left=node1;
    root->right=node2;
    return root;
}
