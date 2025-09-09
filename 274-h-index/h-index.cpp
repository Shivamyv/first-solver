class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            cnt=n-i;
        if(citations[i]>=cnt){
            ans=max(ans,cnt);
        }
         
        }
      
       



     return ans;

    }
};