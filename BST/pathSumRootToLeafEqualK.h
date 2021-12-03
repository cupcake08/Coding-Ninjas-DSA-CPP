#define _VI_ vector<int>
#define _BTN_ BinaryTreeNode<int>*
#define _PB_ push_back

void rootToLeafPathsSumToK(_BTN_ root, int k,_VI_ path = {}) {
    if(!root) return;
    k -= root->data;
    path._PB_(root->data);
    if(!root->left && !root->right){
        if(k==0){  //correct path
            for(auto &x:path) printf("%d ",x);
            printf("\n");
        }
        path.pop_back();
        return;
    }
    rootToLeafPathsSumToK(root->left,k,path);
    rootToLeafPathsSumToK(root->right,k,path);
}
