vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> array;
    if(root==NULL) return array;
    queue<BinaryTreeNode<int> *> q;
    Node<int> *head = nullptr;
    Node<int> *tail = nullptr;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {

        BinaryTreeNode<int> *front = q.front();
        q.pop();
        
        if (front == nullptr)
        {
            array.push_back(head);
            head=nullptr;
            tail=nullptr;
            if(q.empty())
            {
                break;
            }
            q.push(nullptr);
            continue;
        }
        Node<int> *newNode=new Node<int>(front->data);
        if(head==nullptr)
        {
            head=newNode;
            tail=newNode;
        }else
        {
            tail->next=newNode;
            tail=newNode;
        }
        
        if (front->left != nullptr)
        {
            q.push(front->left);
        }
        if (front->right != nullptr)
        {
            q.push(front->right);
        }
    }
    return array;
}
