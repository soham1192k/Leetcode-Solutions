using ll=long long;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        set<ll>av;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
        vector<ll>cnt(n,0);
        for(int i=0;i<n;i++) av.insert(i);
        for(int i=0;i<meetings.size();i++){
            while(!q.empty()&&q.top().first<=meetings[i][0]){
                av.insert(q.top().second);
                q.pop();
            }
            ll start;
            if(av.size()==0) start=q.top().first;
            else start=meetings[i][0];
            ll duration=meetings[i][1]-meetings[i][0];
            ll room;
            if(av.size()!=0) {room=(*av.begin());av.erase(av.begin());}
            else {room=q.top().second;q.pop();}
            q.push({start+duration,room});
            cnt[room]+=1;
        }
        return max_element(cnt.begin(),cnt.end())-cnt.begin();
    }
};