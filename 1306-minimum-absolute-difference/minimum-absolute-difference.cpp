class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       int n=arr.size();
       sort(arr.begin(),arr.end());
       vector<vector<int>>ans;
       int cnt=INT_MAX;
       for(int i=1;i<n;i++){
       if(arr[i]-arr[i-1]<cnt){
        cnt=arr[i]-arr[i-1];
       }
       }
       for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]==cnt){
            ans.push_back({arr[i-1],arr[i]});
        }
       }

    sort(ans.begin(),ans.end());
       
       return ans;

    }
};