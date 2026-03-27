class Solution {
public:
 bool possible(vector<int>& bloomDay,int day, int m, int k){
     int n=bloomDay.size();
     int cnt=0;
     int nobucket=0;
     for(int i=0;i<n;i++){
       if(bloomDay[i]<=day) cnt++;
       else{
        nobucket+=cnt/k;
        cnt=0;
       }
     }
       nobucket+=cnt/k;
       return nobucket>=m;

 }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val = m * 1ll * k * 1ll; 
        if (val > n) return -1; 
        
        int maxelement=*max_element(bloomDay.begin(),bloomDay.end());
        int minelement=*min_element(bloomDay.begin(),bloomDay.end());
        
        int low=minelement,high=maxelement ,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(possible(bloomDay,mid,m,k)){
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