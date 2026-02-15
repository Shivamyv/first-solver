class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        
       for(string word:words){
          int sum=0;
        for(char ch:word){
           
            sum+=weights[ch-'a'];
        }
              sum =sum % 26;
            char mapped='z'-sum;
            ans.push_back(mapped);

            }
        
        return ans;
    }
};