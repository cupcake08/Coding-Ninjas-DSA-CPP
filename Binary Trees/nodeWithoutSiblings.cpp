void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL) return;
    if(root->left && !root->right) printf("%d ",root->left->data);
    if(root->right && !root->left) printf("%d ",root->right->data);
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}
