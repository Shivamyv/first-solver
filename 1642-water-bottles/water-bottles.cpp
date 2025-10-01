class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    
    int empty=numBottles;
    int ans=numBottles;
    while(empty>=numExchange){
        int newbottles=empty/numExchange;
        ans+=newbottles;
        empty=empty % numExchange+newbottles;
    }

      
    return ans;
    }
};