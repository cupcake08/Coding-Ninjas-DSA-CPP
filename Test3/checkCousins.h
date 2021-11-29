#define _VI_ vector<int>
#define _BTN_ BinaryTreeNode<int>*

const int N = 1e5+5;

_VI_ v(N,-1);
bool isSiblingAndHelper(_BTN_ root,int level,int p,int q){
    if(root == NULL) return 0;
    if(root->left && root->left->data == p && root->right && root->right->data == q) return 1;
    if(root->left && root->left->data == q && root->right && root->right->data == p) return 1;
    v[root->data]=level;
    return isSiblingAndHelper(root->left,level+1,p,q) || isSiblingAndHelper(root->right,level+1,p,q);
}

bool isCousin(_BTN_ root, int p, int q) {
    if(root == NULL) return 0;
    if(root->data == p || root->data == q) return 0;
    if(!isSiblingAndHelper(root,0,p,q)) return v[p]==v[q];
    else return 0;
}
