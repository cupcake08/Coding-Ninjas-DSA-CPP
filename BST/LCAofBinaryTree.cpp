
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL) return -1;
    int d = root->data;
    if(d==a || d==b) return d;
    int left = getLCA(root->left,a,b);
    int right = getLCA(root->right,a,b);
    if(left != -1 && right != -1) return d;
    else if(left != -1 && right == -1) return left;
    else if(left == -1 && right != -1) return right;
    else return -1;
}
