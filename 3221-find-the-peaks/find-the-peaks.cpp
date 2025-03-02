class Solution {
public:
        vector<int>ans;
        void binarySearch(vector<int>& mountain, int l, int r){
            if(l<=r){
                int mid = l+((r-l)/2);
                if(mountain[mid] > mountain[mid-1] && 
                mountain[mid] > mountain[mid+1]) ans.push_back(mid);
                binarySearch(mountain,l,mid-1);
                binarySearch(mountain,mid+1, r);
            }
        }
    vector<int> findPeaks(vector<int>& mountain) {
            int l=1,r=mountain.size()-2;
            binarySearch(mountain, l, r);
       return ans;
    }
};