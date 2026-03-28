class Solution {
public:
    bool possible(vector<int>& weights, int days,int capacity){
       int n=weights.size();
       int currentweight=0;
       int currentdays=1;
       for(int i=0;i<n;i++){
          if(weights[i]+currentweight>capacity){
            currentdays++;
            currentweight=0;
          }
          
            currentweight+=weights[i];
          

       }
       return currentdays<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
       int mini=*max_element(weights.begin(),weights.end());
       int maxi = accumulate(weights.begin(), weights.end(), 0);
      int low=mini;
      int high=maxi;
      int ans=high;
      while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(weights,days,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
      }

      return ans;
        
    }
};