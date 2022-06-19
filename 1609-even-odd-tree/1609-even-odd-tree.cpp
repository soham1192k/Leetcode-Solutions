class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int lvl=-1;
        int prev;
        while(!q.empty()){
            queue<TreeNode*>nq;
            lvl++;
            if(lvl%2==1) prev=1000001;
            else prev=0;
            while(!q.empty()){
                TreeNode* v=q.front();
                q.pop();
                if(v->left) nq.push(v->left);
                if(v->right) nq.push(v->right);
                if(lvl%2==1){
                    if(v->val%2==1) return false;
                    if(v->val>=prev) return false;
                }
                else{
                    if(v->val%2==0) return false;
                    if(v->val<=prev) return false;
                }
                prev=v->val;
            }
            q=nq;
        }
        return true;
    }
};