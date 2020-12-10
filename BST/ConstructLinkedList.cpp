pair<Node<int>*,Node<int> *> headAndTail(BinaryTreeNode<int> *root)
{
	pair<Node<int>*,Node<int>*> p;
	p.first=nullptr;
	p.second=nullptr;
	if(root==nullptr) return p;
	Node<int> *middle=new Node<int>(root->data);
	pair<Node<int>*,Node<int>*> left=headAndTail(root->left);
	pair<Node<int>*,Node<int>*> right=headAndTail(root->right);
	if(left.second) left.second->next=middle;
	else left.first=middle;
	if(right.first) middle->next=right.first;
	else right.second=middle;
	p.first=left.first;
	p.second=right.second;
	return p;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return headAndTail(root).first;
}
