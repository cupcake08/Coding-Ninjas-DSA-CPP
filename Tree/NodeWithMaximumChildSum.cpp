int sum(TreeNode<int> *root){
    if(root == NULL) return 0;
    int ans = root->data;
    for(auto &node:root->children) ans += node->data;
    return ans;
}
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root == NULL) return root;
    int s = sum(root);
    TreeNode<int> *ans = root;
    for(auto &node:root->children){
        TreeNode<int> *temp = maxSumNode(node);
        int tempS = sum(temp);
        if(tempS > s){
            s = tempS;
            ans = temp;
        }
    }
    return ans;
}
