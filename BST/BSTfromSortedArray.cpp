BinaryTreeNode<int> *constructTree(int *arr,int si,int ei)
{
    if(si>ei) return NULL;
    int mid=(ei+si)/2;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(arr[mid]);
    root->left=constructTree(arr,si,mid-1);
    root->right=constructTree(arr,mid+1,ei);
    return root;
}
BinaryTreeNode<int> *constructTree(int *arr,int n)
{
	return constructTree(arr,0,n-1);
}
