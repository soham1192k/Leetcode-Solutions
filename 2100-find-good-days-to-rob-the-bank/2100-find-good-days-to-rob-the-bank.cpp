class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        int left[n],right[n];
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        for(int i=1;i<n;i++){
            if(security[i-1]>=security[i]) left[i]=left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(security[i+1]>=security[i]) right[i]=right[i+1]+1;
        }
        vector<int>v;
        for(int i=0;i<=n-1;i++){
            if(left[i]>=time&&right[i]>=time) v.push_back(i);
        }
        return v;
    }
};