class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
      int ans=INT_MAX;
      int index=-1;
       int n=capacity.size();
       for(int i=0;i<n;i++){
        if(capacity[i]>=itemSize && capacity[i]<ans){
          ans=capacity[i];
          index=i;
             
        }
       }
       return index;
       
    }
};