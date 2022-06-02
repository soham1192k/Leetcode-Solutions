class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int minn=1e9+10;
        int left=0,right=1;
        map<int,int>mp;
        mp[cards[0]]++;
        while(right<n){
            if(mp[cards[right]]==0){
                mp[cards[right]]++;
            }
            else{
                mp[cards[right]]++;
                while(left<=right&&mp[cards[right]]>1){
                    mp[cards[left]]--;
                    left++;
                }
                minn=min(minn,right-left+2);
            }
            right++;
        }
        if(minn==1e9+10) return -1;
        return minn;
    }
};