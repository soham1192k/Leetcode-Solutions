class Solution {
public:
    int sum=0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        root->right=bstToGst(root->right);
        sum+=root->val;
        root->val=sum;
        root->left=bstToGst(root->left);
        return root;
    }
};

