class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
    int n=grid.size();
      vector<int>zerocounts(n,0);
      for(int i=0;i<n;i++){
        int count=0;
        int j=n-1;
        while(j>=0 && grid[i][j]==0){
            count++;
            j--;

        }
        zerocounts[i]=count;
      }
      int steps=0;
      for(int i=0;i<n;i++){
        int need=n-i-1;
        int j=i;
        while(j<n && zerocounts[j] <need){
            j++;
        }
        if(j==n) return -1;
        steps+=j-i;

        while(j>i){
            swap(zerocounts[j],zerocounts[j-1]);
            j--;
        }
      }
     
     return steps;



    }
};