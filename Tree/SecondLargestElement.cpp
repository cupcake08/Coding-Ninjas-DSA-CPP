void change(TreeNode<int> *root,int m)
{
	if(root==nullptr) return;
	if(root->data==m)
	{
		root->data=INT_MIN;
	}
	for(int i=0;i<root->children.size();i++)
	{
		change(root->children[i],m);
	}
}
TreeNode<int> *largest(TreeNode<int> *root)
{
	if(root==nullptr) return root;
	int max=root->data;
	TreeNode<int> *maxNode=root;
	for(int i=0;i<root->children.size();i++)
	{
		TreeNode<int> *large=largest(root->children[i]);
		if(large==nullptr)
		{
			continue;
		}
		if(max<large->data)
		{
			max=large->data;
			maxNode=large;
		}
	}
	return maxNode;
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
	if(root==nullptr) return NULL;
	int large=largest(root)->data;
	change(root,large);
	return largest(root);
}
