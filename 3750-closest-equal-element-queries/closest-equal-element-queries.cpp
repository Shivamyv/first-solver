class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
       unordered_map<int,vector<int>>mpp;
       for(int i=0;i<n;i++){
        mpp[nums[i]].push_back(i);
       }
       vector<int>ans;
      for(int q:queries){
        int val=nums[q];
        auto &vec=mpp[val];
        if(vec.size()==1){
        ans.push_back(-1);
        continue;
        }
        
        int pos=lower_bound(vec.begin(),vec.end(),q)-vec.begin();
        int res=INT_MAX;
        
            int right=vec[(pos+1)%vec.size()];
            int d=abs(q-right);
            int circulardist=n-d;
            res=min({res,d,circulardist});

       int left=vec[(pos-1+vec.size())%vec.size()];
       d =abs(q-left);
       circulardist=n-d;
       res=min({res,d,circulardist});


        
       ans.push_back(res);
      }
    return ans;
      
    }
};