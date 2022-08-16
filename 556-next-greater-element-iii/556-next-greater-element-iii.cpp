class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        bool flag=false;
        int idx;int minn=1e9;int pp;
        for(int i=s.length()-1;i>=1;i--){
            if(s[i]>s[i-1]){
                for(int j=i;j<s.length();j++){
                    if(s[j]>s[i-1]&&minn>s[j]-'0'){
                        pp=j;
                        minn=s[j]-'0';
                    }
                }
                swap(s[pp],s[i-1]);
                idx=i;
                flag=true;
                break;
            }
        }
        if(!flag) return -1;
        sort(s.begin()+idx,s.end());
        long long curr=0;
        long long val=1;
        for(int i=s.length()-1;i>=0;i--){
            curr+=(s[i]-'0')*val;
            val*=10;
        }
        if(curr>=(1ll<<31)) return -1;
        return curr;
    }
};