class Solution {
 public:
      int maxelement(vector<int>& piles){
        
        int maxi=INT_MIN;
        int n=piles.size();

        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
      }
   double f(vector<int>& piles, int h){
    double totalhrs = 0.0;
   
    double n=piles.size();
    for(double i=0;i<n;i++){
       totalhrs += ceil((double) piles[i] / (double) h);

    }
    return totalhrs;

   }
  
    int minEatingSpeed(vector<int>& piles, int h) {
      int n=piles.size();
     
      int low=1,high=maxelement(piles);
      while(low<=high){
        int mid=(low+high)/2;
       double totalhrs = f(piles,mid);
      if(totalhrs <=h){
        high=mid-1;
      }
      else{
        low=mid+1;

      }


      }
      
        return low; 
    }
};