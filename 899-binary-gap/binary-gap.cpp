class Solution {
public:
    int binaryGap(int n) {
        
        int prev=-1;
        
        int ans=0;
      for(int current=0;current<32;current++){
        if(((n>>current)&1)>0){
            ans= (prev!=-1)?max(ans,current-prev):ans;
            prev=current;
        }
      }


       return ans;
    }
};