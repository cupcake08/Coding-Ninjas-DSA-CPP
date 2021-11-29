#define tn TreeNode<int>*
void replaceWithDepthValue(tn root,int m=0) {
    root->data = m;
    for(auto &node:root->children) replaceWithDepthValue(node,m+1);
}
