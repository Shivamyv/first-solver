class Solution {
public:
    
    bool func(vector<vector<char> > & board, int i, int j, string& word, int k) {
      
        if (k == word.length()) {
            return true;
        }
       
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[k] != board[i][j]) {
            return false;
        }

      
        bool ans = false;

       
        char x = board[i][j];
        board[i][j] = ' ';

        
        ans |= func(board, i + 1, j, word, k + 1);
        ans |= func(board, i - 1, j, word, k + 1);
        ans |= func(board, i, j + 1, word, k + 1);
        ans |= func(board, i, j - 1, word, k + 1);

       
        board[i][j] = x;
        
        return ans;
    }

   
    bool exist(vector<vector<char> >& board, string word) {
      
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
               
                if (board[i][j] == word[0]) {
                 
                    if (func(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
      
        return false;
    }
};