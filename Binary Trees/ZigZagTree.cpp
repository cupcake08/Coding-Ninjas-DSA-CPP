#include <stack>
void zigZagOrder(BinaryTreeNode<int> *root)
{

    stack<BinaryTreeNode<int> *> stRtoL;
    stack<BinaryTreeNode<int> *> stLtoR;
    stRtoL.push(root);
    while (!(stRtoL.empty() && stLtoR.empty()))
    {

        while (!stRtoL.empty())
        {
            BinaryTreeNode<int> *front = stRtoL.top();
            stRtoL.pop();
            cout << front->data << " ";
            if (front->left != nullptr)
            {
                stLtoR.push(front->left);
            }
            if (front->right != nullptr)
            {
                stLtoR.push(front->right);
            }
        }
        cout << endl;
        while (!stLtoR.empty())
        {
            BinaryTreeNode<int> *top = stLtoR.top();
            stLtoR.pop();
            cout << top->data << " ";
            if (top->right != nullptr)
            {
                stRtoL.push(top->right);
            }
            if (top->left != nullptr)
            {
                stRtoL.push(top->left);
            }
        }
        cout << endl;
    }
}
