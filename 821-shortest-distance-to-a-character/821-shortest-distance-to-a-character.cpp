class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        map<int,int>left,right;
        if(s[0]==c) left[0]=0;
        else left[0]=1e9;
        if(s[n-1]==c) right[n-1]=0;
        else right[n-1]=1e9;
        for(int i=1;i<n;i++){
            if(s[i]==c) left[i]=0;
            else left[i]=left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]==c) right[i]=0;
            else right[i]=right[i+1]+1;
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++) ans[i]=min(left[i],right[i]);
        return ans;
    }
};