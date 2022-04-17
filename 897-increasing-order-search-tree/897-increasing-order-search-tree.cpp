class Solution {
public:
    vector<int>inorder;
    void traverse(TreeNode* root){
        if(root==NULL) return ;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        TreeNode* head=new TreeNode();
        TreeNode* tmp=head;
        for(auto x:inorder){
            TreeNode* temp=new TreeNode();
            temp->val=x;
            tmp->right=temp;
            tmp=tmp->right;
        }
        return head->right;
    }
};