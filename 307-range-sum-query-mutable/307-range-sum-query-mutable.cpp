class NumArray {
public:
    static const int mxN=12*1e4+10;
    int n;
    int st[mxN];
    void build(int si,int ss,int se,vector<int>& nums){
        if(ss==se) {st[si]=nums[ss];return;}
        int mid=(ss+se)>>1;
        build(2*si+1,ss,mid,nums);
        build(2*si+2,mid+1,se,nums);
        st[si]=st[2*si+1]+st[2*si+2];
    }
    int query(int si,int ss,int se,int qs,int qe){
        if(qs<=ss&&qe>=se) return st[si];
        if(qs>se||qe<ss) return 0;   
        int mid=(ss+se)>>1;
        return query(2*si+1,ss,mid,qs,qe)+query(2*si+2,mid+1,se,qs,qe);
    }
    void update(int si,int ss,int se,int qi,int val){
        if(ss==se) {st[si]=val;return;}
        int mid=(ss+se)>>1;
        if(qi<=mid) update(2*si+1,ss,mid,qi,val);
        else update(2*si+2,mid+1,se,qi,val);
        st[si]=st[2*si+1]+st[2*si+2];
    }
    NumArray(vector<int>& nums) {
        n=(int)nums.size();
        build(0,0,n-1,nums);
    }
    void update(int index, int val) {
        return update(0,0,n-1,index,val);
    }
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};