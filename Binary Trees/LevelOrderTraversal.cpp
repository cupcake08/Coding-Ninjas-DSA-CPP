#define _BTN_ BinaryTreeNode<int>*

void printLevelWise(_BTN_ root) {
    if(root == NULL) return;
    queue<_BTN_> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        if(front==NULL){
            if(q.empty()) break;
            printf("\n");
            q.push(NULL);
            continue;
        }
        printf("%d ",front->data);
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
}
