class Solution {
public:
    // DFS Backtrack
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[0]){
                    dfs(board, i, j, 0, word, found);
                    if(found) return true;
                }
            }
        }
        return false;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, int idx, string& word, bool& found){
        if(found) return;
        if(idx == word.size()){
            found = true;
            return;
        }
        if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == word[idx] && idx < word.size()){
            char backtrack = board[i][j];
            board[i][j] = '*';
            dfs(board, i-1, j, idx+1, word, found);
            dfs(board, i+1, j, idx+1, word, found);
            dfs(board, i, j-1, idx+1, word, found);
            dfs(board, i, j+1, idx+1, word, found);
            board[i][j] = backtrack;
        }
    }
};