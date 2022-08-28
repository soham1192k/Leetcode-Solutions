class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        for(int i=1;i<travel.size();i++) travel[i]+=travel[i-1];
        int ans=0,g_ind=0,p_ind=0,m_ind=0;
        for(int i=n-1;i>=0;i--){
            for(auto x:garbage[i]){
                if(g_ind==0&&x=='G') g_ind=i;
                if(m_ind==0&&x=='M') m_ind=i;
                if(p_ind==0&&x=='P') p_ind=i;
            }
        }
        if(g_ind>=1) ans+=travel[g_ind-1];
        if(p_ind>=1) ans+=travel[p_ind-1];
        if(m_ind>=1) ans+=travel[m_ind-1];
        for(int i=0;i<=g_ind;i++){
            for(auto x:garbage[i]){
                if(x=='G') ans++;
            }
        }
        for(int i=0;i<=m_ind;i++){
            for(auto x:garbage[i]){
                if(x=='M') ans++;
            }
        }
        for(int i=0;i<=p_ind;i++){
            for(auto x:garbage[i]){
                if(x=='P') ans++;
            }
        }
        return ans;
    }
};