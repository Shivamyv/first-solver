class Solution {
public:
    int getLeastFrequentDigit(int n) {
      int cnt=INT_MAX;
      int num=10;
       vector<int>ans; 
       while (n > 0) {
      ans.push_back(n % 10);
       n /= 10;
    }
       
        unordered_map<int,int>mpp;
        for(auto it:ans){
            mpp[it]++;
        }
        for(auto&p:mpp){
       int digit=p.first;
       int nodigit=p.second;
       if(nodigit < cnt || (nodigit==cnt && num>digit)){
      cnt=nodigit;
      num=digit;
       }
        }
    return num;

    }
};