class Solution {
public:
const long long mod=1e9+7;
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int>current(m+1,0);
        vector<int>prev(m+1,0);
       prev[0]=1;

     
     for(int i=1;i<=n;i++){
        current[0]=1;
        for(int j=1;j<=m;j++){
            
        if(s[i-1]==t[j-1]){
        current[j]=(prev[j-1]+prev[j]) %mod;
    }  
    else{
        current[j]=prev[j]%mod;
    } 

  
        }
        prev=current;
     }
       return prev[m];
       

    }
};