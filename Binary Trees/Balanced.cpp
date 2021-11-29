#define _BTN_ BinaryTreeNode<int>*
#define _PB_ pair<int,bool>
#define balanced second
#define height first

_PB_ check(_BTN_ root){
    if(root == NULL) return {0,1};
    _PB_ left = check(root->left);
    _PB_ right = check(root->right);
    bool flag = 1;
    if(!left.balanced || !right.balanced || abs(left.height - right.height) > 1) flag=0;
    return {max(left.height,right.height)+1,flag};
}
bool isBalanced(_BTN_ root) { return check(root).balanced; }
