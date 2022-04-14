class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        int temp=root->val;
        if(temp==val) return root;
        else if(temp>val) return searchBST(root->left,val);
        return searchBST(root->right,val);
    }
};