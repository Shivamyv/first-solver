class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        
        int maxfruit=0;
        int left=0;
       unordered_map<int,int>mpp;
       for(int right=0;right<n;right++){
        mpp[fruits[right]]++;
       
     while (mpp.size() > 2){
        mpp[fruits[left]]--;
     
        if(mpp[fruits[left]]==0){
            mpp.erase(fruits[left]);
        }
        left++;
     }
     maxfruit=max(maxfruit,right-left+1);
    }
     return maxfruit;

    }
};