class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        long long leftsum=0,rightprod=1;
        while(j!=i){
            if(leftsum<rightprod){
                leftsum+=nums[i];
                i++;
            }
            else{
                rightprod*=nums[j];
                j--;

            }


        }
        return leftsum==rightprod?i:-1;

    }
};