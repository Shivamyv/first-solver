class Solution {
public:
    string minWindow(string s, string t) {
      int n=s.size();
     int sIndex=-1;
     int minlen=INT_MAX;
     int l=0,r=0;
     int cnt=0;
    int hash[256]={0};

    for(int i=0;i<t.size();i++){
        hash[t[i]]++;
    }
     while(r<n){
        if(hash[s[r]]>0){
            cnt++;
        }
        hash[s[r]]--;
     
     while(cnt==t.size()){
        if(r-l+1<minlen){
        minlen=r-l+1;
       sIndex=l;
        }
        hash[s[l]]++;
        if(hash[s[l]]>0){
            cnt--;
        }
        l++;

     }
     r++;
    }
     return (sIndex==-1)?"":s.substr(sIndex,minlen);




    }
};