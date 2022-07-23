class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        map<int,bool>mp;
        int cnt=0;
        int complete=0;
        for(int i=0;i<rolls.size();i++){
            if(!mp[rolls[i]]) {cnt++;mp[rolls[i]]=true;}
            if(cnt==k){
                mp.clear();
                cnt=0;
                complete++;
            }
        }
        return complete+1;
    }
};