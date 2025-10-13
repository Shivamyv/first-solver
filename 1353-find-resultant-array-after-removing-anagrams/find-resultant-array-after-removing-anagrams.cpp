class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
    int n=words.size();
    vector<string>ans;
    string prev="";
    for(string word:words){
        string sortedword=word;
        sort(sortedword.begin(),sortedword.end());
        if(sortedword!=prev){
            ans.push_back(word);
            prev=sortedword;
        }
    }

    return ans;
    }
};