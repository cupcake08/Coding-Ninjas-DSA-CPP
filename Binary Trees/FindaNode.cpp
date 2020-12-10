bool isNodePresent(BinaryTreeNode<int> *root,int x)
{
    if(root==nullptr) return false;
	if(root->data == x) return true;
	return isNodePresent(root->left,x)||isNodePresent(root->right,x);
}
