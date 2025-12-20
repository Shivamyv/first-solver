class Solution {
public:
 bool isunsorted( vector<string>& strs,int j){
    for(int i=1;i<strs.size();i++){
        if(strs[i][j]<strs[i-1][j])
        return true;
    }
        return false;
    
 }
    int minDeletionSize(vector<string>& strs) {
        int res=0;
        int n=strs.size();
        for(int j=0;j<strs[0].size();j++){
            res+=isunsorted(strs,j);
        }

    return res;
    }
};