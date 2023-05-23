class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        // check col
        // check box
        
        // Create sets, as every element must be unique
        vector<vector<char>> row;
        vector<vector<char>> col;
        vector<vector<char>> box;
        
        for (auto i = 0; i < 9; i++) {
            vector<char> subrow;
            vector<char> subcol;
            vector<char> subbox;
            
            row.push_back(subrow);
            col.push_back(subcol);
            box.push_back(subbox);
        }
        
        for (auto i = 0; i < 9; i++) {
            for (auto j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                
                if (std::count(row[i].begin(), row[i].end(), board[i][j])) {
                    return false;
                } else {
                    row[i].push_back(board[i][j]);
                }
                
                if (std::count(col[j].begin(), col[j].end(), board[i][j])) {
                    return false;
                } else {
                    col[j].push_back(board[i][j]);
                }
                
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