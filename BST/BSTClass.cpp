class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = nullptr;
    }
    ~BST()
    {
        delete root;
    }

private:
    bool search(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return search(data, node->left);
        }
        else
        {
            return search(data, node->right);
        }
    }

public:
    bool search(int data)
    {
        return search(data, root);
    }

private:
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data <= node->data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }

public:
    void insert(int data)
    {
        root = insert(data, root);
    }

private:
    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data > data)
        {
            node->left = remove(data, node->left);
            return node;
        }
        else if (node->data < data)
        {
            node->right = remove(data, node->right);
            return node;
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = nullptr;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != nullptr)
                {
                    minNode = minNode->left;
                }
                int minData = minNode->data;
                node->data = minData;
                node->right = remove(minData, node->right);
                return node;
            }
        }
    }

public:
    void remove(int data)
    {
        root = remove(data, root);
    }

private:
    void printTree(BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != nullptr)
        {
            cout << "L:" << node->left->data << ",";
        }
        if (node->right != nullptr)
        {
            cout << "R:" << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }

public:
    void print()
    {
        printTree(root);
    }
};
