class Solution {
public:
    int dp[1001][1001];
    int arr[1001];
    int func(string& floor,int left,int len,int idx){
        if(idx<0) return 0;
        if(dp[left][idx]!=-1) return dp[left][idx]; 
        int ans=0;
        if(floor[idx]=='1'){
            int no_whites=arr[idx];
            if(idx-len>=0) no_whites-=arr[idx-len]; 
            int op1=-1;
            if(left>=1) op1=no_whites+func(floor,left-1,len,idx-len);
            int op2=func(floor,left,len,idx-1);
            ans=max(op1,op2);
        }
        else{
            ans=func(floor,left,len,idx-1);
        }
        return dp[left][idx]=ans;
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n=floor.length();
        memset(dp,-1,sizeof(dp));
        if(floor[0]=='1') arr[0]=1;
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1];
            if(floor[i]=='1') arr[i]+=1;
        }
        return arr[n-1]-func(floor,numCarpets,carpetLen,n-1);
    }
};