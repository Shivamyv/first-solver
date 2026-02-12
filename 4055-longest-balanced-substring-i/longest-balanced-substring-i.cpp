class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            int maxfreq=0;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
           maxfreq=max(maxfreq,mpp[s[j]]);
            int maxlength=j-i+1;
           if(maxlength==maxfreq*mpp.size()){
            maxi=max(maxi,maxlength);
           } 
        }
        }
    
      
    return maxi;

    }
};