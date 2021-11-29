#include <climits>
#include <algorithm>

#define _PI_ pair<int,int>
#define _MIN_ first
#define _MAX_ second

_PI_ getMinAndMax(BinaryTreeNode<int> *root) {
	if(root == NULL) return {INT_MAX,INT_MIN};
    _PI_ ans = {root->data,root->data};
    _PI_ left = getMinAndMax(root->left);
    _PI_ right = getMinAndMax(root->right);
    ans._MIN_ = min({ans._MIN_,left._MIN_,right._MIN_});
    ans._MAX_ = max({ans._MAX_,left._MAX_,right._MAX_});
    return ans;
}
