BinaryTreeNode<int>* binaryTreeHelper(int *postOrder,int *inOrder,int poS,int poE,int inS,int inE)
{
    if(poS>poE || inS > inE)
    {
        return nullptr;
    }
    int rootData=postOrder[poE];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(inOrder[i]==rootData)
        {
            rootIndex=i;
            break;
        }
    }
    int leftInS=inS;
    int leftInE=rootIndex-1;
    int leftPoS=poS;
    int leftPoE=poS+rootIndex-inS-1;
    int rightInS=rootIndex+1;
    int rightInE=inE;
    int rightPoS=leftPoE+1;
    int rightPoE=poE-1;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    root->left=binaryTreeHelper(postOrder,inOrder,leftPoS,leftPoE,leftInS,leftInE);
    root->right=binaryTreeHelper(postOrder,inOrder,rightPoS,rightPoE,rightInS,rightInE);
    return root;

}
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return binaryTreeHelper(postorder,inorder,0,postLength-1,0,inLength-1);
}
