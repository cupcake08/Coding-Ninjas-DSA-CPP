void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root==nullptr) return;
    if(root->left!=nullptr && root->right==nullptr)
    {
        cout<<root->left->data<<" ";
    }
    if(root->right!=nullptr && root->left == nullptr)
    {
        cout<<root->right->data<<" ";
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}
