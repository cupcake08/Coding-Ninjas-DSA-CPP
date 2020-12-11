int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if(root==nullptr)
    {
        return -1;
    }
    if(root->data == val1 || root->data == val2)
    {
        return root->data;
    }
    int x=-1;
    int y=-1;
    if(val1 > root->data && val2>= root->data)
    {
        y=getLCA(root->right,val1,val2);
    }else if(val1 <root->data && val2<root->data)
    {
        x=getLCA(root->left,val1,val2);
    }
    x=getLCA(root->left,val1,val2);
    y=getLCA(root->right,val1,val2);
    if(x==-1 && y!=-1)
    {
        return y;
    }else if(x!=-1 && y==-1)
    {
        return x;
    }else if(x!=-1 && y!=-1)
    {
        return root->data;
    }
    return -1;
}
