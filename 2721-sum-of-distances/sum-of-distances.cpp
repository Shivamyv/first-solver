class Solution {
public:
    vector<long long> distance(vector<int>& nums)
    {
        unordered_map<int, vector<int>> um;
        for(int i=0;i<nums.size();i++){um[nums[i]].push_back(i);}
        vector<long long> arr(nums.size(), 0);
        for(auto itr: um)
        {
            vector<int> curr = itr.second;
            if(curr.size()>1)
            {
                vector<long long> pref(curr.size()+1);
                pref[0]=0;
                for(int i=1;i<curr.size()+1;i++){pref[i]=pref[i-1]+curr[i-1];}
                for(int i=0;i<curr.size();i++)
                {
                    arr[curr[i]]=(2*i+1-curr.size())*(curr[i])+pref[curr.size()]-pref[i+1]-pref[i];
                }
            }
        }
        return arr;
    }
};