class Solution {
public:
    int minCost(int n) {
        int ans=0;
        int cost=0;
        int x=0;
        while(n!=1){
         x=1 + n-1;

        cost+=1*n-1;
        n--;



        }
        return cost;

    }
};