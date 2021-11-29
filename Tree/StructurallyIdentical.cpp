bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1 == NULL && root2 != NULL) return false;
    if(root1 != NULL && root2 == NULL) return false;
    if(root1 == NULL && root2 == NULL) return 1;
    if(root1->data != root2->data) return 0;
    if(root1->children.size() != root2->children.size()) return 0;
    for(int i=0;i<root1->children.size();i++) if(!areIdentical(root1->children[i],root2->children[i])) return 0;
    return 1;
}
