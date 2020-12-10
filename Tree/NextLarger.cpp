TreeNode<int>* getNextLargerElement(TreeNode<int> *root, int n) {
	if(root==nullptr) return root;
	TreeNode<int> *ans=nullptr;	
	if(root->data > n)
	{
		ans=root;
	}
	for(int i=0;i<root->children.size();i++)
	{
		TreeNode<int> *temp=getNextLargerElement(root->children[i],n);
		if(ans==nullptr)
		{
			ans= temp;
		}else if(temp != nullptr && temp->data < ans->data)
		{
			ans = temp;
		}
	}
	return ans;
}
