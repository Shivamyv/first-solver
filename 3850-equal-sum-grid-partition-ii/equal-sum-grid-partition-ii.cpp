class Solution {
public:
  typedef long long ll;
 bool check(vector<vector<int>>& grid,long long totalsum){
      int m=grid.size();
      int n=grid[0].size();
      unordered_set<ll>st;
      long long top=0;
      for(int i=0;i<m-1;i++){
        for(int j=0;j<n;j++){
            st.insert(grid[i][j]);
            top+=grid[i][j];
        }
        long long bottom=(totalsum-top);
        long long diff=(top-bottom);
        if(diff==0) return true;
        if(diff==(ll)grid[0][0]) return true;
        if(diff==(ll)grid[0][n-1]) return true;
        if(diff==(ll)grid[i][0]) return true;
        if(i>0 && n>1 && st.count(diff) ) return true;
      } 
      return false;
 }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        long long totalsum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                totalsum+=grid[i][j];
            }
        }
        if(check(grid,totalsum)){
            return true;
        }
        reverse(grid.begin(),grid.end());
        if(check(grid,totalsum)) return true;
        reverse(grid.begin(),grid.end());

        vector<vector<int>>transpose(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                transpose[j][i]=grid[i][j];
            }
        }
        if(check(transpose,totalsum)){
            return true;

        }
        reverse(transpose.begin(),transpose.end());
        if(check(transpose,totalsum)){
            return true;
        }
   return false;

    }
};