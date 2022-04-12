int nx[8]={-1,-1,-1,0,0,1,1,1};
int ny[8]={-1,0,1,-1,1,-1,0,1};
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                for(int p=0;p<8;p++){
                    int ni=i+nx[p];
                    int nj=j+ny[p];
                    if(ni>=0&&nj>=0&&ni<n&&nj<m){
                        if(board[ni][nj]==1||board[ni][nj]==2) cnt++;
                    } 
                }
                if(board[i][j]==1){
                    if(cnt<2) board[i][j]=2;
                    else if(cnt>3) board[i][j]=2;
                }
                else{
                    if(cnt==3) board[i][j]=3;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2) board[i][j]=0;
                else if(board[i][j]==3) board[i][j]=1;
            }
        }
    }
};