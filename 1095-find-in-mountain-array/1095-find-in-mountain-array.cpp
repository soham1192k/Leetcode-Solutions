class Solution {
public:
    int func(MountainArray& a,int low,int high,int target,bool asc){
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=a.get(mid);
            if(val==target) return mid;
            else if(val<target){
                if(asc) low=mid+1;
                else high=mid-1;
            } 
            else{
                if(asc) high=mid-1;
                else low=mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &a) {
        int n=a.length();
        int low=0,high=n-1;
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            int v1=a.get(mid);
            int v2=-1,v3=-1;
            if(mid-1>=low) v2=a.get(mid-1);
            if(mid+1<=high) v3=a.get(mid+1);
            if(v2==-1&&v3==-1) {ans=mid;break;}
            else if(v2==-1){
                if(v3>v1) low=mid+1;
                else {ans=mid;high=mid-1;}
            }
            else if(v3==-1){
                if(v2<v1) {ans=mid;low=mid+1;}
                else high=mid-1;
            }
            else{
                if(v2<v1&&v1<v3) low=mid+1;
                else if(v2>v1&&v1>v3) high=mid-1;
                else if(v2<v1&&v3<v1) {ans=mid;break;}
            }
        }
        int val=func(a,0,ans,target,true);
        if(val==-1) val=func(a,ans+1,n-1,target,false);
        return val;
    }
};