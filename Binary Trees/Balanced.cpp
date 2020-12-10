pair<int,bool> heightAndBalance(BinaryTreeNode<int> *root)    //first=height,second=isBalanced
{
	pair<int,bool> p(0,true);
	if(root==NULL) return p;
	pair<int,bool> leftAns=heightAndBalance(root->left);
	pair<int,bool> rightAns=heightAndBalance(root->right);
	bool flag;
	if(!(leftAns.second)||!(rightAns.second)||abs(leftAns.first-rightAns.first)>1) flag=false;
	else flag=true;
	p.first=max(leftAns.first,rightAns.first)+1;
	p.second=flag;
	return p;
}
bool isBalanced(BinaryTreeNode<int> *root)
{
	return heightAndBalance(root).second;
}
