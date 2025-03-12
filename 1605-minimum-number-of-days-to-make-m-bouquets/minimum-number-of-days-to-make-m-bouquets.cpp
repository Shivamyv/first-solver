class Solution {
public:

    bool f(vector<int>& bloomDay,int days,int m,int k){
        int n=bloomDay.size();
        int cnt=0;
        int pos=0;
         for(int i=0;i<n;i++){
        if(bloomDay[i]<=days){
      cnt++;
    }
    else{
      pos+=(cnt/k);
      cnt=0;
    }
   }
  pos+=(cnt/k);
  return pos >=m;
    }
        
     


    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int ans=-1;
       int maxi=INT_MIN;
       int mini=INT_MAX;
       for(int i=0;i<n;i++){
        maxi=max(maxi,bloomDay[i]);
        mini=min(mini,bloomDay[i]);
        }   
     
        int low=mini,high=maxi;
         long long val = m * 1ll * k * 1ll; 
        if(val > n ) return -1; 

        while(low<=high){
            int mid=(low+high)/2;
             
        if(f(bloomDay,mid,m,k)){
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