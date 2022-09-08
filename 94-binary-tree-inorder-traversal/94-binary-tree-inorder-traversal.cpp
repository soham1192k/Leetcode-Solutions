class Solution {
public:
    vector<int>ans;
    void func(TreeNode* root){
        if(!root) return;
        func(root->left);
        ans.push_back(root->val);
        func(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        func(root);
        return ans;
    }
};