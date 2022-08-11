class Solution {
public:
    bool helper(TreeNode* root,TreeNode* minn,TreeNode* maxx){
        if(!root) return true;
        if(minn&&root->val<=minn->val||maxx&&root->val>=maxx->val) return false;
        return helper(root->left,minn,root)&&helper(root->right,root,maxx);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL); 
    }
};