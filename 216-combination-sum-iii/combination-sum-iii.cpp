class Solution {
public:
  void f(int sum,int last,vector<int> &arr,int k, vector<vector<int>> &ans){

  if(sum==0 && arr.size()==k){
    ans.push_back(arr);

    return;
  }
  if(sum<0 || arr.size()> k) return;

for(int i=last;i<=9;i++){
    if(i<=sum){
        arr.push_back(i);
        f(sum-i,i+1,arr,k,ans);
        arr.pop_back();
    }
    else{
        break;
    }
}

  }

    vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> arr;
   
  f(n,1,arr,k,ans);



   return ans;
   
    } 	
};