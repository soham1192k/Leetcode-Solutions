class Solution {
public:
    vector<TreeNode*>v;
    void store(TreeNode* root,int height,int depth){
        if(root==NULL) return;
        if(height==depth-1) {v.push_back(root);return;}
        store(root->left,height+1,depth);
        store(root->right,height+1,depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        store(root,1,depth);
        if(v.size()==0){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        for(auto x:v){
            TreeNode* left=x->left;
            TreeNode* right=x->right;
            TreeNode* newleft=new TreeNode(val);
            TreeNode* newright=new TreeNode(val);
            newleft->left=left;
            newright->right=right;
            x->left=newleft;
            x->right=newright;
        }
        return root;
    }
};