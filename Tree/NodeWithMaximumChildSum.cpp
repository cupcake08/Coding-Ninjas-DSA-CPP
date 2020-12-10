#include <climits>
int childSum(TreeNode<int> *root)
{
	int sum=root->data;
	for(int i=0;i<root->children.size();i++)
	{
		sum+=root->children[i]->data;
	}
	return sum;
}
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
	int rootSum=childSum(root);
	TreeNode<int> *mxChildSum=root;
	int mxSum=INT_MIN;
	for(int i=0;i<root->children.size();i++)
	{
		TreeNode<int> *temp=maxSumNode(root->children[i]);
		int tempSum=childSum(temp);
		if(tempSum > mxSum)
		{
			mxSum=tempSum;
			mxChildSum=temp;
		}
	}
	if(rootSum > mxSum) return root;
	return mxChildSum;
}
