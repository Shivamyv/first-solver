class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =matrix.size(), n = size(matrix[0]);
        int l = 0, r = m-1,mid;
        while(l<=r){
            mid = l+((r-l)/2);
            if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                break;
            }
            else if(matrix[mid][0]>target){
                r=mid-1;
            }
            else if(matrix[mid][n-1]<target){
                l=mid+1;
            }
        }
        int lr=0,rr=n-1,rmid;
        while(lr<=rr){
         rmid = lr+((rr-lr)/2);
            if(matrix[mid][rmid]==target) return true;
            else if(matrix[mid][rmid]>target) rr=rmid-1;
            else lr = rmid+1;
        }
        return false;
    }
};