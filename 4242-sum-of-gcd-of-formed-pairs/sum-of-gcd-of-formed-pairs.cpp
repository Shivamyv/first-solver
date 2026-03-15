class Solution {
public:
typedef long long ll;
   ll gcd(ll a,ll b){
    while(b!=0){
        ll temp=b;
        b=a%b;
        a=temp;
    }
    return a;
   }

    long long gcdSum(vector<int>& nums) {
         int n=nums.size();
         
         vector<ll>prefixgcd(n);
         ll mx=0;
       for(int i=0;i<n;i++){
        mx=max(mx,(ll)nums[i]);
        prefixgcd[i]=gcd(mx,nums[i]);
       }
       sort(prefixgcd.begin(),prefixgcd.end());
       ll ans=0;
      ll i=0,j=n-1;
      while(i<j){
        ans+=gcd(prefixgcd[i],prefixgcd[j]);
        i++;
        j--;
      }

   return ans;


    }
};