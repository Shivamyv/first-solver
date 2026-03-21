class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid,
                                         int x, int y, int k) {


     int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans;
        int firstrow=x;
        int lastrow=x+k-1;
        
        for(int i=0;i<k/2;i++){
            for(int j=0;j<k;j++){
              
                    swap(grid[firstrow+i][y+j],grid[lastrow-i][y+j]);
                    
                
            }
        }

      return grid;
        
    }
};