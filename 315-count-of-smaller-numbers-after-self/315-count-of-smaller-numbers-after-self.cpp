class Solution {
public:
    int st[100005];
    void update(int si,int ss,int se,int idx){
        if(ss==se){
            st[si]++;
            return;
        }
        int mid=(ss+se)>>1;
        if(idx<=mid) update(2*si+1,ss,mid,idx);
        else update(2*si+2,mid+1,se,idx);
        st[si]=st[2*si+1]+st[2*si+2];
    }
    int query(int si,int ss,int se,int qs,int qe){
        if(qs>se||qe<ss) return 0;
        if(qs<=ss&&qe>=se) return st[si];
        int mid=(ss+se)>>1;
        return query(2*si+1,ss,mid,qs,qe)+query(2*si+2,mid+1,se,qs,qe);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) nums[i]+=10000;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            ans.push_back(query(0,0,20000,0,nums[i]-1));
            update(0,0,20000,nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};