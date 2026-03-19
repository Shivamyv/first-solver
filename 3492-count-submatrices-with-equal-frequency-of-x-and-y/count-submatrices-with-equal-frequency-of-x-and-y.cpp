class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
     int n=grid.size();
     int m=grid[0].size();
     vector<vector<int>>cummX(n,vector<int>(m,0));
        vector<vector<int>>cummY(n,vector<int>(m,0));
       int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             cummX[i][j]=(grid[i][j]=='X');
              cummY[i][j]=(grid[i][j]=='Y'); 
              if(i-1>=0){
           cummX[i][j]+=cummX[i-1][j];
            cummY[i][j]+=cummY[i-1][j];
              }
            if(j-1>=0){
             cummX[i][j]+=cummX[i][j-1];
               cummY[i][j]+=cummY[i][j-1];
            }
            if(i-1>=0 && j-1>=0){
                cummX[i][j]-=cummX[i-1][j-1];
                  cummY[i][j]-=cummY[i-1][j-1];
            }
            if(cummX[i][j]== cummY[i][j] && cummX[i][j]>0){
                count++;
            }
        }
      }
   return count;
    }
};