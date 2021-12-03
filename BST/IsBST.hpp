bool isBST(BinaryTreeNode<int> *root)
{
	if(root==NULL) return 1;
	if(root->left && root->left->data > root->data) return 0;
	if(root->right && root->right->data < root->data) return 0;
	return isBST(root->left) & isBST(root->right);  //you can use '&&' operator here as well
}
