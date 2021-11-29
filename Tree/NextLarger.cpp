TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if(root == NULL) return root;
    TreeNode<int> *ans = NULL;
    if(root->data > x) ans = root;
    for(auto &node:root->children){
        TreeNode<int> *temp = getNextLargerElement(node,x);
        if(ans == NULL) ans = temp;
        else if(temp != NULL && temp->data < ans->data) ans = temp;
    }
    return ans;
}
