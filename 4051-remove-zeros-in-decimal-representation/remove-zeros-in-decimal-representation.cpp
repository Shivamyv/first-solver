class Solution {
public:
    long long removeZeros(long long n) {
        string x;
        string ans=to_string(n);
       for(int i=0;i<ans.size();i++){
        if(ans[i]!='0'){
            x+=ans[i];
        }
       }
    return stol(x);

    }
};