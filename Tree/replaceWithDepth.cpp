void replaceWithDepthValueHelper(TreeNode<int> *root,int m)
{
	root->data=m;
	for(int i=0;i<root->children.size();i++)
	{
		replaceWithDepthValueHelper(root->children[i],m+1);
	}
}
void replaceWithDepthValue(TreeNode<int> *root)
{
	replaceWithDepthValueHelper(root,0);
}
