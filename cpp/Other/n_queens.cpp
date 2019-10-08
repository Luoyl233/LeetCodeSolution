/**
 * 51. N-Queens
 */

#include "common.h"

#if LEET_CODE == 51

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        findPos(n, 0, board, res);

        return res;
    }

    void findPos(int n, int depth, vector<string>& board, vector<vector<string>>& res) {
        if (depth == n) {
            res.push_back(board);
        } else {
            for (int col=0; col < n; col++) {
                if (isLegal(depth, col, board, n)) {
                    board[depth][col] = 'Q';
                    findPos(n, depth + 1, board, res);
                    board[depth][col] = '.';
                }
            }
        }
    }

    bool isLegal(int row, int col, vector<string>& board, int n) {
        for (int i=1; i <= row; i++) {
            if (board[row-i][col] == 'Q'
                || ((col-i) >= 0 && board[row-i][col-i] == 'Q')
                || ((col+i) < n && board[row-i][col+i] == 'Q'))
                return false;
        }
        return true;
    }

};



#endif
