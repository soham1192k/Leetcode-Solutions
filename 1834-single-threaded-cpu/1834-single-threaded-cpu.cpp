class Solution {
public:
    using pii=pair<pair<int,int>,int>;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<pii>v;
        for(int i=0;i<n;i++) v.push_back({{tasks[i][0],tasks[i][1]},i});
        sort(v.begin(),v.end());
        long long curr=v[0].first.first;
        priority_queue<pii,vector<pii>,greater<pii>>q;
        int ptr=0;
        vector<int>ans;
        while(ptr<n){
            while(ptr<n&&v[ptr].first.first<=curr){
                q.push({{v[ptr].first.second,v[ptr].second},v[ptr].first.first});
                ptr++;
            }
            if(!q.empty()){
                pii t=q.top();
                q.pop();
                ans.push_back(t.first.second);
                curr+=t.first.first;
            }
            else curr=v[ptr].first.first;
        }
        while(!q.empty()){
            pii t=q.top();
            q.pop();
            ans.push_back(t.first.second);
            curr+=t.first.first;
        }
        return ans;
    }
};