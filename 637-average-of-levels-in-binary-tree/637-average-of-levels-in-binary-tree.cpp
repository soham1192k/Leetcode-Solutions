class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty()){
            queue<TreeNode*>nq;
            long long sum=0,cnt=0;
            while(!q.empty()){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
                cnt+=1;
                if(curr->left) nq.push(curr->left);
                if(curr->right) nq.push(curr->right);
            }
            q=nq;
            ans.push_back((1.0*sum)/cnt);
        }
        return ans;
    }
};