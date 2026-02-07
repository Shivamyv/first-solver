class Solution {
public:
    int minimumDeletions(string s) {
       int n= s.size();
       int bcount=0;
       int deletion=0;
       for(char ch:s){
        if(ch=='b'){
            bcount++;
        }
        else{
            deletion=min(deletion+1,bcount);
        }
       }
       
      return deletion;
    }
};