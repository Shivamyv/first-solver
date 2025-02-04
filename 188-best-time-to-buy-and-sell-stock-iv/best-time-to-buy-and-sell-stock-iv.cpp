class Solution {
public:
    int maxProfit(int cnt, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> front(2,vector<int>(cnt+1,0)),curr(2,vector<int>(cnt+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<cnt+1;k++){
                    int profit=0;
                    if(j){
                        int pick=-prices[i]+front[false][k];
                        int notPick=0+front[true][k];
                        profit=max(pick,notPick);
                    }   
                    else{
                        int pick=prices[i]+front[true][k-1];
                        int notPick=0+front[false][k];
                        profit=max(pick,notPick);
                    }
                    curr[j][k]=profit;
                }
            }
            front=curr;
        }
        return front[true][cnt];
    }
};