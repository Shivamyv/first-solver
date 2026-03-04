class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int cnt=0;
      vector<int>rowcount(n,0);
      vector<int>colcount(m,0);
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                rowcount[i]++;
                colcount[j]++;
            }
        }
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1 && rowcount[i]==1 && colcount[j]==1) cnt++;
        }
      }
     
     return cnt;
    }
};