class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1(1, nums[0]), arr2(1, nums[1]);
        for(int i = 2;i < nums.size();i++){
            if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();