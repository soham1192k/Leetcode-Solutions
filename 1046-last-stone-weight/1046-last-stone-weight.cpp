class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>q;
        for(auto x:stones) q.push(x);
        while(q.size()>1){
            int x=q.top();
            q.pop();
            int y=q.top();
            q.pop();
            if(x!=y) q.push(abs(y-x));
        }
        if(q.size()==0) return 0;
        return q.top();
    }
};