class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>&
           dictionary) {
        int n=queries.size();
       
        vector<string>ans;
          for(int i=0;i<n;i++){
            string c=queries[i];
            for(int j=0;j<dictionary.size();j++){
                string ch=dictionary[j];
                int cnt=0;
             for(int k=0;k<c.size();k++){
                if(c[k]!=ch[k]){
                    cnt++;
                }
             }
             if(cnt<=2){
                ans.push_back(c);
                break;
             }
        }
     }



     return ans;


        
    }
};