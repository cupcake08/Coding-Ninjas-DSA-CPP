#define _NODE_ Node<int>
#define _V_(T) vector<T>
#define _BTN_ BinaryTreeNode<int>*

_V_(_NODE_*) constructLinkedListForEachLevel(_BTN_ root){
    if(root == NULL) return {};
    queue<_BTN_> q;
    q.push(root);
    q.push(NULL);
    _NODE_ *head = NULL,*tail=NULL;
    _V_(_NODE_*) ans;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        if(front == NULL){
            ans.push_back(head);
            head = NULL;
            tail = NULL;
            if(q.empty()) break;
            q.push(NULL);
            continue;
        }
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
        _NODE_ *newNode = new _NODE_(front->data);
        if(head){
            tail->next = newNode;
            tail = newNode;
        }else{
            head = newNode;
            tail = newNode;
        }
    }
    return ans;
}
