bool isPresent(TreeNode<int>* root, int x) {
    if(root == NULL) return 0; //not necessary on CN platform
    if(root->data == x) return 1;
    for(auto &node:root->children) if(isPresent(node,x)) return 1;
}
