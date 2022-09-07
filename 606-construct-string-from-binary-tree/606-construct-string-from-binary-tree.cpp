class Solution {
public:
    string ans;
    void dfs(TreeNode* root){
        if(!root) return;
        ans+=to_string(root->val);
        if(root->left&&root->right){
            ans+='(';
            dfs(root->left);
            ans+=')';
            ans+='(';
            dfs(root->right);
            ans+=')';
        }
        else if(root->left){
            ans+='(';
            dfs(root->left);
            ans+=')';
        }
        else if(root->right){
            ans+='(';
            ans+=')';
            ans+='(';
            dfs(root->right);
            ans+=')';
        }
    }
    string tree2str(TreeNode* root) {
        dfs(root);
        return ans;
    }
};