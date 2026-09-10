class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int steps=it.first;
            int row=it.second.first;
            int col=it.second.second;

            dist[row][col]=steps;
            for(int i=0;i<4;i++){
                int nrow=dr[i]+row;
                int ncol=dc[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                    q.push({steps+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            } 

        }


    return dist;
        
    }
};