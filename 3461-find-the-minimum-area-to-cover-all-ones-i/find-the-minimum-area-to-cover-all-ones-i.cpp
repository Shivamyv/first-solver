class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
         int minirow=n,maxirow=-1;
         int minicol=m,maxicol=-1;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxirow=max(maxirow,i);
                    maxicol=max(maxicol,j);
                    minirow=min(minirow,i);
                    minicol=min(minicol,j);
                    int height=maxirow-minirow+1;
                    int weight=maxicol-minicol+1;
                    ans=height*weight;
                }
               
               

            }
         }
         
                if(maxirow==-1) return 0;
         
         return ans;
    }
};