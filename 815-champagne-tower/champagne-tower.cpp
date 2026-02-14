class Solution {
public:
   double memo[101][101];
   double f(int poured,int i,int j){
    if(j<0 || j>i) return 0.0;
     if(i==0 && j==0) return poured;

    if(memo[i][j]!=-1.0) return memo[i][j];
   double left=f(poured,i-1,j-1);
   double right=f(poured,i-1,j);
   double fromleft=max(0.0,(left-1.0)/2.0);
   double fromright=max(0.0,(right-1.0)/2.0);
   return memo[i][j]=fromleft+fromright;

   }


    double champagneTower(int poured, int query_row, int query_glass) {
     
        
      
       for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            memo[i][j]=-1.0;
       
       
        
     return min(1.0,f(poured,query_row,query_glass));

    }
};