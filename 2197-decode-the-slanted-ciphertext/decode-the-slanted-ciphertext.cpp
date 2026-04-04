class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        if(rows==1) return encodedText;
       
        int cols=n/rows;
        string originalText="";
        vector<vector<char>>ans(rows,vector<char>(cols));
        int idx=0;
       for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            ans[i][j]=encodedText[idx++];
        }
       } 
       for(int col=0;col<cols;col++){
        int i=0;
        int j=col;
        while (i < rows && j < cols) {
                originalText += ans[i][j];
                i++;
                j++;
            }
        }
         while (!originalText.empty() && originalText.back() == ' ') {
            originalText.pop_back();
        }
        return originalText;
    }
};