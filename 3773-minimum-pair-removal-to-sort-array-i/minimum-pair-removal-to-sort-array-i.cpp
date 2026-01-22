class Solution {
public:
// bool arraysorted(vector<int>& nums){
//     for(int i=0;i<n;i++){
//         if(nums[i]<nums[i+1]) return true;
//     }
//     return false;
// }
   int minpair(vector<int>pair){
    int minsum=INT_MAX;
    int pos=-1;
    for(int i=0;i<pair.size()-1;i++){
        if(pair[i]+pair[i+1]<minsum){
            minsum=pair[i]+pair[i+1];
            pos=i;
        }
    }
    return pos;
   }
   void mergepair(vector<int>&pair,int pos){
    pair[pos]+=pair[pos+1];
    pair.erase(pair.begin()+pos+1);
   }


    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int ops=0;
        while(!is_sorted(nums.begin(),nums.end())){
                mergepair(nums,minpair(nums));
        ops+=1;
        
    }

    return ops;
    }
};