class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++) v[i]={growTime[i],plantTime[i]};
        sort(v.rbegin(),v.rend());
        int plantday=0,days=0;
        for(int i=0;i<n;i++){
            pair<int,int>curr=v[i];
            days=max(days,plantday+curr.first+curr.second);
            plantday+=curr.second;
        }
        return days;
    }
};

