void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if(root){
        int val = root->data;
        if(val >=k1 && val <=k2){
            elementsInRangeK1K2(root->left,k1,k2);
            printf("%d ",val);
            elementsInRangeK1K2(root->right,k1,k2);
        }else if(val < k1) elementsInRangeK1K2(root->right,k1,k2);
        else if(val > k2) elementsInRangeK1K2(root->left,k1,k2);
    }
}
