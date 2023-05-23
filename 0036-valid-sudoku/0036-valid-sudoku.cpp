class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Create vec of vecs
        vector<vector<char>> row;
        vector<vector<char>> col;
        vector<vector<char>> box;
        
        // Push sub vecs into vecs
        for (auto i = 0; i < 9; i++) {
            vector<char> subrow;
            vector<char> subcol;
            vector<char> subbox;
            
            row.push_back(subrow);
            col.push_back(subcol);
            box.push_back(subbox);
        }
        
        // Iterate through the sudoku board
        for (auto i = 0; i < 9; i++) {
            for (auto j = 0; j < 9; j++) {
                
                // If empty, skip
                if (board[i][j] == '.') {
                    continue;
                }
                
                // Check if exists in row, if does - return false, otherwise push to row vec
                if (std::count(row[i].begin(), row[i].end(), board[i][j])) {
                    return false;
                } else {
                    row[i].push_back(board[i][j]);
                }
                
                // Check if exists in col, if does - return false, otherwise push to col vec
                if (std::count(col[j].begin(), col[j].end(), board[i][j])) {
                    return false;
                } else {
                    col[j].push_back(board[i][j]);
                }
                
                // Check if exists in box, if does - return false, otherwise push to box vec using math magic
                if (std::count(box[(j / 3)* 3 + i / 3].begin(), box[(j / 3)* 3 + i / 3].end(), board[i][j])) {
                    return false;
                } else {
                    box[(j / 3)* 3 + i / 3].push_back(board[i][j]);
                }
            }
        }
        
        return true;
    }
};