class Solution {
public:
    // int f(int i,int j,string &s, string &p,vector<vector<int>> &dp){
    //     if(i<0 && j<0) return true;
    //     if(i<0 && j>=0) return false;
    //     if(j<0 && i>=0) {
    //         for(int ii=0;ii<=i;ii++){
    //             if(s[ii]!='*') return false;
    //         }
    //         return true;
    //     }
    //         if(dp[i][j]!=-1) return dp[i][j];
        
    //     if(s[i]==p[j] || s[i] =='?'){
    //         return dp[i][j]= f(i-1,j-1,s,p,dp);

    //     }
    //     if(s[i]=='*'){
    //         return dp[i][j]= f(i-1,j,s,p,dp) |f(i,j-1,s,p,dp);
    //     }
    //     return dp[i][j]= false;
    // }
   
    // bool isMatch(string s, string p) {
    //     int n=s.size();
    //     int m=p.size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return f(n-1,m-1,s,p,dp);

 bool solve(int index1, int index2, string &text, string &pattern,vector<vector<int>> &dp) {
        if (index1 < 0 && index2 < 0) return true;
        if (index2 < 0 && index1 >= 0) return false;
        if (index1 < 0 && index2 >= 0) {
            for (int i = 0; i <= index2; i++) {
                if (pattern[i] != '*') return false;
            }
            return true;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        if (text[index1] == pattern[index2] || pattern[index2] == '?') {
            return dp[index1][index2]=solve(index1 - 1, index2 - 1, text, pattern,dp);
        }

        if (pattern[index2] == '*') {
            return dp[index1][index2]=solve(index1 - 1, index2, text, pattern,dp) || solve(index1, index2 - 1, text, pattern,dp);
        }

        return dp[index1][index2]=false;
    }

    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(n1-1, n2-1, s, p,dp);
    }
};