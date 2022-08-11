class Solution {
public:
    map<TreeNode*,int>left,right;
    int maxx=-1001;
    void func(TreeNode* root){
        if(!root) return;
        if(root&&!root->right&&!root->left) {left[root]=max(0,root->val);right[root]=max(0,root->val);maxx=max(maxx,root->val);return;}
        func(root->left);
        func(root->right);
        left[root]=root->val;
        if(root->left) left[root]+=max(left[root->left],right[root->left]);
        right[root]=root->val;
        if(root->right) right[root]+=max(left[root->right],right[root->right]);
        maxx=max({maxx,root->val,left[root],right[root],left[root]+right[root]-root->val});
    }
    int maxPathSum(TreeNode* root) {
        func(root);
        return maxx;
    }
};