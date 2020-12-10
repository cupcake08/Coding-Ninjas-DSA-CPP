int height(BinaryTreeNode<int> *root)
{
    if(root==nullptr) return 0;
	  int leftHeight=height(root->left);
	  int rightHeight=height(root->right);
	  return max(leftHeight,rightHeight)+1;
}
