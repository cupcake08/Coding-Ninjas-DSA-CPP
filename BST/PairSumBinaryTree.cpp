#include <vector>
#include <algorithm>
vector<int> convertTreeToArray(BinaryTreeNode<int> *root)
{
    vector<int> v;
    if(root==nullptr)
    {
        return v;
    }
    vector<int> leftArray=convertTreeToArray(root->left);
    vector<int> rightArray=convertTreeToArray(root->right);
    for(int i:leftArray)
    {
        v.push_back(i);
    }
    for(int i:rightArray)
    {
        v.push_back(i);
    }
    v.push_back(root->data);
    return v;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    if(root==nullptr)
    {
        return;
    }
    vector<int> v=convertTreeToArray(root);
    sort(v.begin(),v.end());
    int i=0;
    int j=v.size()-1;
    while(i<j)
    {
        if(v[i]+v[j]==sum)
        {
            cout<<v[i]<<" "<<v[j]<<endl;
            i++;
            j--;
        }else if(v[i]+v[j]<sum)
        {
            i++;
        }else
        {
            j--;
        }
        
    }

}
