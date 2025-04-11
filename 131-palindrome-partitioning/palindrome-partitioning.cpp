class Solution {
public:

void f(int index, string s, vector<string> &path, vector<vector<string>> &res){
    if(index==s.size()){
        res.push_back(path);
        return;
    }

    for(int i=index;i<s.size();i++){
        if(palindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            f(i+1,s,path,res);
            path.pop_back();
        }
    }
}
bool palindrome(string s,int start,int end){
    while(start <= end){
    if(s[start++]!=s[end--]){
       
        return false;
       
    }
    }
    return true;

    
}


    vector<vector<string> > partition(string s) {
      vector<vector<string>> res;
      vector<string> path;
      f(0,s,path,res);
      return res; 
    }
};