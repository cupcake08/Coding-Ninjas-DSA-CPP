#include <algorithm>

#define _BTN_ BinaryTreeNode<int>*
#define vi vector<int>

vi v;
void helper(_BTN_ root){
    if(root){
        v.push_back(root->data);
        helper(root->left);
        helper(root->right);
    }
}
void pairSum(_BTN_ root, int sum) {
    helper(root);
    sort(begin(v),end(v));
    int i=0,j=v.size()-1;
    while(i<j){
        int s = v[i]+v[j];
        if(s==sum){
            printf("%d %d\n",v[i],v[j]);
            i++,j--;
        }else if(s < sum) i++;
        else j--;
    }
}
