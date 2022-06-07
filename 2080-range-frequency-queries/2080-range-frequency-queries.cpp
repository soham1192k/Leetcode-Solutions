class RangeFreqQuery {
public:
    map<int,vector<int>>mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) mp[arr[i]].push_back(i);
    }    
    int query(int left, int right, int value) {
        int i1=lower_bound(mp[value].begin(),mp[value].end(),left)-mp[value].begin();
        int i2=upper_bound(mp[value].begin(),mp[value].end(),right)-mp[value].begin();
        i2-=1;
        return i2-i1+1;
    }
};
