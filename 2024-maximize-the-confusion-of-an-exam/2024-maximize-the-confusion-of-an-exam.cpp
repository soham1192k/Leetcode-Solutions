class Solution {
public:
    bool ok(vector<pair<int,int>>&v,int n,int mid,int k){
        for(int i=0;i<=n-mid;i++){
            int trues,falses;
            if(i==0){
                trues=v[i+mid-1].first;
                falses=v[i+mid-1].second;
            }
            else{
                trues=v[i+mid-1].first-v[i-1].first;
                falses=v[i+mid-1].second-v[i-1].second;
            }
            if(min(trues,falses)<=k) return true;
        } 
        return false;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length();
        vector<pair<int,int>>v;
        if(answerKey[0]=='T') v.push_back({1,0});
        else v.push_back({0,1});
        for(int i=1;i<n;i++){
            if(answerKey[i]=='T') v.push_back({v.back().first+1,v.back().second});
            else v.push_back({v.back().first,v.back().second+1});
        }
        int low=1;
        int high=n;
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ok(v,n,mid,k)){
                ans=max(ans,mid);
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};