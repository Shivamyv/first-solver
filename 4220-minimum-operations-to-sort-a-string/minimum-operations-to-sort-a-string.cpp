class Solution {
public:
bool issorted(string s){
    int n=s.size();
    for(int i=0;i<n-1;i++){
        if(s[i]>s[i+1]) return false;
    }
    return true;
}
    int minOperations(string s) {
        int n=s.size();
        if(issorted(s)) return 0;
        if(n==2) return -1;
        char mn=*min_element(s.begin(),s.end());
        char mx=*max_element(s.begin(),s.end());
        if(s[0]==mn || s[n-1]==mx) return 1;

          string one=s,two=s;
          sort(begin(one),begin(one)+n-1);
          sort(begin(one)+1,end(one)); 

          sort(begin(two)+1,end(two));
          sort(begin(two),begin(two)+n-1);
          if(issorted(one) || issorted(two)) return 2;
        return 3;
    }
};