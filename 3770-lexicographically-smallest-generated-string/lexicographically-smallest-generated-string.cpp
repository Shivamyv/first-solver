class Solution {
public:
  bool issame(string &word, string & str2, int i, int m){
    for(int j=0;j<m;j++){
        if(word[i]!=str2[j]){
            return false;
        }
        i++;
    }
    return true;
  }
    string generateString(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int N=n+m-1;
        string word(N,'$');
        vector<bool> canchange(N, false);
        for(int i=0;i<n;i++){
        if(str1[i]=='T'){
         int i1=i; 
        for(int j=0;j<m;j++){
          if(word[i1]!='$' && word[i1]!=str2[j]){
               return "";
          }
          word[i1]=str2[j];
          i1++;
         }
        } 
        }
        
        for(int i=0;i<N;i++){
            if(word[i]=='$'){
                word[i]='a';
                canchange[i]=true;
            }
        }
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
              if(issame(word,str2,i,m)){

           bool change=false;
           for(int k=i+m-1;k>=i;k--){
            if(canchange[k]==true){
                word[k]='b';
                change=true;
                break;
            }
           }
        if(change==false) {
            return "";
        }

            }
            }
        }
      return word;


    }
};