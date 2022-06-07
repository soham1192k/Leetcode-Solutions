class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* leftmost=NULL;
        TreeNode* rightmost=NULL;
        map<TreeNode*,TreeNode*>par;
        par[root]=root;
        while(!q.empty()){
            queue<TreeNode*>nq;
            leftmost=NULL;
            rightmost=NULL;
            while(!q.empty()){
                TreeNode* v=q.front();
                q.pop();
                if(leftmost==NULL) leftmost=v;
                rightmost=v;
                if(v->left) {nq.push(v->left);par[v->left]=v;}
                if(v->right) {nq.push(v->right);par[v->right]=v;}
            }
            q=nq;
        }
        while(leftmost!=rightmost){
            leftmost=par[leftmost];
            rightmost=par[rightmost];
        }
        return leftmost;
    }
};