void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(root==nullptr) return;
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    BinaryTreeNode<int> *newNode=new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *temp=root->left;
    root->left=newNode;
    newNode->left=temp;
}
