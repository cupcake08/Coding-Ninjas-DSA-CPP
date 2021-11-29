/*

Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.

Sample Input 1 :
 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1 :
9
3
6
5

*/

#define _BTN_ BinaryTreeNode<int>*
#define _V_ vector<int>
#define pb push_back

_V_* longestPath(_BTN_ root) {
	if(root == NULL) return NULL;
    if(!root->left && !root->right){
        _V_ *ans = new _V_();
        ans->pb(root->data);
        return ans;
    }
    _V_ *left = longestPath(root->left);
    _V_ *right = longestPath(root->right);
    if(!left){
    	right->pb(root->data);
        return right;
    }
    else if(!right){
        left->pb(root->data);
        return left;
    }else{
        if(left->size() > right->size()){
            left->pb(root->data);
            delete right;
            return left;
        }else{
            right->pb(root->data);
            delete left;
            return right;
        }
    }
}
