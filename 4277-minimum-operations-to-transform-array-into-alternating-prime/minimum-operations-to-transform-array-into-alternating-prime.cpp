class Solution {
public:
    bool isprime(int n){
        if(n <= 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;

        for(int i = 3; i * i <= n; i += 2){
            if(n % i == 0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(i % 2 == 0) {
               
                int x = nums[i];
                while(!isprime(x)) {
                    x++;
                    ans++;
                }
            }
            else {
               
                if(isprime(nums[i])) {
                    if(nums[i] == 2) ans += 2;
                    else ans += 1;
                }
            }
        }

        return ans;
    }
};