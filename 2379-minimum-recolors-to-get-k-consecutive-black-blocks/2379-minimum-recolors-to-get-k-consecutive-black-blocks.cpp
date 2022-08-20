class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int b=0,w=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B') b++;
            else w++;
        }
        int minn=w;
        for(int i=k;i<n;i++){
            if(blocks[i-k]=='B') b--;
            else w--;
            if(blocks[i]=='B') b++;
            else w++;
            minn=min(minn,w);
        }
        return minn;
    }
};