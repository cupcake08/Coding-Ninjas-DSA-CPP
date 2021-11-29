bool isBST(BinaryTreeNode<int> *root)
{
	if(root==NULL) return true;
	if(root->left && root->left->data > root->data) return false;
	if(root->right && root->right->data < root->data) return false;
	return isBST(root->left) & isBST(root->right);  //you can use '&&' operator here as well
}
