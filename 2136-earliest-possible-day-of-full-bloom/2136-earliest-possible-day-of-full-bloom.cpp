class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++) v[i]={growTime[i],plantTime[i]};
        sort(v.rbegin(),v.rend());
        priority_queue<pair<int,int>>q;
        for(int i=0;i<n;i++) q.push(v[i]);
        int plantday=0,days=0;
        while(!q.empty()){
            pair<int,int>curr=q.top();
            q.pop();
            days=max(days,plantday+curr.first+curr.second);
            plantday+=curr.second;
        }
        return days;
    }
};

