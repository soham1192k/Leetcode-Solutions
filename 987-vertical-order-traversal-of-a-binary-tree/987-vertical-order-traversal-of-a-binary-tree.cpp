class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        map<int,multiset<int>>loc;
        map<int,vector<int>>glob;
        while(!q.empty()){
            queue<pair<TreeNode*,int>>nq;
            loc.clear();
            while(!q.empty()){
                pair<TreeNode*,int>curr=q.front();
                q.pop();
                loc[curr.second].insert(curr.first->val);
                if(curr.first->left) nq.push({curr.first->left,curr.second-1});
                if(curr.first->right) nq.push({curr.first->right,curr.second+1});
            }
            for(auto x:loc){
                for(auto itr=x.second.begin();itr!=x.second.end();itr++) glob[x.first].push_back(*itr);
            }
            q=nq;
        }
        vector<int>hold;
        for(auto x:glob){
            for(auto y:x.second){
                hold.push_back(y);
            }
            ans.push_back(hold);
            hold.clear();
        }
        return ans;
    }
};