class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=1;i<n;i++){
            if(heights[i-1]>=heights[i]) ;
            else{
                q.push(heights[i]-heights[i-1]);
                if(q.size()>ladders){
                    int diff=q.top();
                    q.pop();
                    if(bricks>=diff) bricks-=diff;
                    else return i-1;
                }
            }
        }
        return n-1;
    }
};

