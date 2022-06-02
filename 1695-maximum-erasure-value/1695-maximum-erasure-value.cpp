class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        map<int,int>mp;
        sum+=nums[0];
        mp[sum]=1;
        int maxx=sum;
        int left=0,right=1;
        while(right<n){
            if(mp[nums[right]]==0){
                sum+=nums[right];
                maxx=max(maxx,sum);
                mp[nums[right]]++;
            }   
            else{
                sum+=nums[right];
                mp[nums[right]]++;
                while(left<=right&&mp[nums[right]]>1){
                    sum-=nums[left];
                    mp[nums[left]]--;
                    left++;
                }
                maxx=max(maxx,sum);
            }
            right++;
        }
        return maxx;
    }
};

