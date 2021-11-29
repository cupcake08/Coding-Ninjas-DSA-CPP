#define pt pair<TreeNode<int>*,TreeNode<int>*>
#define ss second
#define ff first

pt *largest(TreeNode<int> *root){
    if(root == NULL) return new pt({NULL,NULL});
    pt *ans = new pt({root,NULL});
    for(auto &node:root->children){
        pt *sub = largest(node);
        if(sub->ff->data > ans->ff->data){
            if(sub->ss == NULL){
                ans->ss = ans->ff;
                ans->ff = sub->ff;
            }else{
                if(sub->ss->data > ans->ff->data){
                    ans->ss = sub->ss;
                    ans->ff = sub->ff;
                }else{
                    ans->ss = ans->ff;
                    ans->ff = sub->ff;
                }
            }
        }else if(ans->ff->data != sub->ff->data && (ans->ss == NULL || sub->ff->data > ans->ss->data)) ans->ss = sub->ff;
    }
    return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    return largest(root)->ss;
}
