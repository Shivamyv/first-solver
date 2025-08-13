class Solution {
public:
   vector<int>prefixmax(vector<int> & arr,int  &n){
    vector<int>prefix(n);
    prefix[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        prefix[i]=max(prefix[i-1],arr[i]);
    }
   return prefix;
  }
  vector<int>suffixmax(vector<int> & arr,int n){
    vector<int>suffix(n);
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=max(suffix[i+1],arr[i]);
    }
    return suffix;
  }


    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
         vector<int>leftmax=prefixmax(height,n);
         vector<int>rightmax=suffixmax(height,n);
      for(int i=0;i<n;i++){
      if(height[i]< leftmax[i] && height[i]<rightmax[i]){
        total+=(min(rightmax[i],leftmax[i])-height[i]);
      }


      }
       
     return total;
        
    }
};