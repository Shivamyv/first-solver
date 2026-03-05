class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int n=grid.size();
      priority_queue<
      tuple<int,int,int>,
      vector<tuple<int,int,int>>,
      greater<tuple<int,int,int>>
      >pq;

      vector<vector<int>>visited(n,vector<int>(n,0));

      pq.push({grid[0][0],0,0});
        visited[0][0]=1;
      while(!pq.empty()){
        int dr[]={-1,0,1,0};
        int dc[]={0,+1,0,-1};
        auto[cost ,r ,c]=pq.top();
        pq.pop();
       if(r==n-1 && c==n-1) return cost;
       for(int i=0;i<4;i++){
        int delrow=r+dr[i];
        int delcol=c+dc[i];

        if(delrow<n && delrow>=0 && delcol<n && delcol>=0 && !visited[delrow][delcol]){          visited[delrow][delcol]=1;
        int newcost=max(cost,grid[delrow][delcol]);
            pq.push({newcost,delrow,delcol});
        }
       }

      }
    return -1;


    }
};