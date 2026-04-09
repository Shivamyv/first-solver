class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       int n=time.size();
       int cnt=0;
       vector<int>freq(60,0);
       for(int t:time){
        int rem=t%60;
        int need=(60-rem)%60;
        cnt+=freq[need];
        freq[rem]++;
       }
       
       return cnt;

    }
};