int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL) return -1;
    int d = root->data;
    if(d==a || d==b) return d;
    int left=-1,right=-1;
    if(a>d && b >= d) right = getLCA(root->right,a,b);
    else if(a < d && b < d) left = getLCA(root->left,a,b);
    else{
        left = getLCA(root->left,a,b);
        right = getLCA(root->right,a,b);
    }
    if(left != -1 && right != -1) return d;
    else if(left != -1) return left;
    return right;
}
