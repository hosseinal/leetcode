class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,bool> rowMap;
        for (int i = 0; i < 9; i++){
        
            rowMap.clear();
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                if (rowMap.count(board[i][j]) > 0){
                    return false;
                }
                rowMap[board[i][j]] = true;
            }

            rowMap.clear();
            for (int j = 0; j < 9; j++){
                    if (board[j][i] == '.') continue;
                    if (rowMap.count(board[j][i]) > 0){
                        return false;
                    }
                    rowMap[board[j][i]] = true;
            }
        }
        
        for (int i = 0; i < 9; i+=3){
            for (int j = 0; j < 9; j+=3){
                rowMap.clear();
                for (int ii = 0; ii < 3; ii++){
                    for (int jj = 0; jj < 3; jj++){
                        char val = board[i + ii][j + jj]; // Absolute position
                        if (val == '.') continue;
                        if (rowMap.count(board[i+ii][j+jj]) > 0){
                            return false;
                        }
                        rowMap[board[i+ii][j+jj]] = true;
                    }
                }
            }
        }

        return true;
    }
};

