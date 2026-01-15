class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int ans;
      int x=hBars.size();
      int y=vBars.size();
      sort(hBars.begin(),hBars.end());
      sort(vBars.begin(),vBars.end());
      int curr=1,maxh=1;
      for(int i=1;i<x;i++){
       if(hBars[i]==hBars[i-1]+1){
        curr++;
       }
       else curr=1;
        maxh=max(maxh,curr);
      }
      curr=1;
      int maxv=1;
     for(int i=1;i<y;i++){
        if(vBars[i]==vBars[i-1]+1){
            curr++;
        }
        else{
            curr=1;
         
        }
         maxv=max(maxv,curr);
     }
      int side=min(maxh+1,maxv+1);
      return side*side;


    

    }
};