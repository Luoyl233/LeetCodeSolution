/*
 * 36. Valid Sudoku
*/

#include "common.h"

#if LEET_CODE == 36

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, bool> um;
        int rows = board.size();
        int cols = board.front().size();

        string checkRow = ".r0";
        string checkCol = ".c0";
        string checkCell = ".b00";
        for (int i=0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                if (board[i][j] == '.')
                    continue;

                checkRow[0] = board[i][j];
                checkCol[0] = board[i][j];
                checkCell[0] = board[i][j];

                checkRow[2] = '0' + i;
                checkCol[2] = '0' + j;
                checkCell[2] = '0' + (i / 3);
                checkCell[3] = '0' + (j / 3);
                if (um.find(checkRow) != um.end() ||
                    um.find(checkCol) != um.end() ||
                    um.find(checkCell) != um.end())
                    return false;
                else {
                    um[checkRow] = true;
                    um[checkCol] = true;
                    um[checkCell] = true;
                }
            }
        }

        return true;
    }

};


int main()
{

    return 0;
}


#endif
