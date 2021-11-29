#define BTN BinaryTreeNode<int>*
void swap(BTN root){
    if(root->left && root->right){
        BTN temp = root->left;
    	root->left = root->right;
    	root->right = temp;
    }
}
void mirrorBinaryTree(BTN root) {
    if(root == NULL) return;
    swap(root);
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
