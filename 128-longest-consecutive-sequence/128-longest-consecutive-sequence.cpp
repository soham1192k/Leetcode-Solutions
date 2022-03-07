class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        map<int,bool>mp;
        for(int i=0;i<n;i++) mp[nums[i]]=true;
        int maxlen=0;
        map<int,bool>done;
        for(int i=0;i<n;i++){
            if(mp[nums[i]-1]==true) ;
            else if(!done[nums[i]]){
                int j;
                for(j=nums[i];;j++){
                    if(mp[j]==false) break;
                }
                maxlen=max(maxlen,j-nums[i]);
                done[nums[i]]=true;
            }
        }
        return maxlen;
    }
};