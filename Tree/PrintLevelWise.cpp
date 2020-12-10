void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int>*> child;
    child.push(root);
    while(!child.empty())
    {
        TreeNode<int>* front=child.front();
        child.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++)
        {
            TreeNode<int> *childo=front->children[i];
            cout<<childo->data;
            if(i!=front->children.size()-1)
            {
                cout<<',';
            }
            child.push(childo);
        }
        cout<<endl;
    }
    
}
