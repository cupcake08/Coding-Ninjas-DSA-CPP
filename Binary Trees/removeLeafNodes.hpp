#define _BTN_ BinaryTreeNode<int>*

_BTN_ removeLeafNodes(_BTN_ root) {
    if(root == NULL) return root;
    if(root->left == NULL && root->right == NULL) return NULL;
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}
