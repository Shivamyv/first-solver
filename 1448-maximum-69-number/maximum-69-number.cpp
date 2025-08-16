class Solution {
public:
    int maximum69Number (int num) {
        int maxi=INT_MIN;
       
        string ans=to_string(num);
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='6'){ 
            ans[i]='9';
            
           break;
            }
           
        }
        return stoi(ans);
    }
};