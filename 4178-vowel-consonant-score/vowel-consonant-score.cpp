class Solution {
public:
    int vowelConsonantScore(string s) {
        int n=s.size();
        int score=0;
        int v=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]>='a'&& s[i]<='z'){
            if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'||s[i]=='o'||s[i]=='u'){
                 v++;
            }
            else{
                c++;
            }
            }
            if(c>0){
                score=floor(v/c);
            }
            
        }
     return score;

    }
};