TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root==nullptr) return root;
    TreeNode<int> *maxNode=root;
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int> * maxNodeTemp=maxDataNode(root->children[i]);
        if(maxNode->data < maxNodeTemp->data)
        {
            maxNode=maxNodeTemp;
        }
    }
    return maxNode;
}
