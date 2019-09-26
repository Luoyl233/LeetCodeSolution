/*
 * 79. Word Search
 */


#include "common.h"


#if LEET_CODE == 79

// TODO: Optimize. This solution is too complex.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0)
            return word.empty();
        if (word.empty())
            return true;

        int cols = board.front().size();
        bool flag = false;

        for (int i = 0; i < rows && !flag; i ++) {
            for (int j = 0; j < cols && !flag; j ++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '.';
                    flag = exist(board, i, j, word, 1);
                    board[i][j] = word[0];
                }
            }
        }

        return flag;
    }

    bool exist(vector<vector<char>>& board, int curRow, int curCol , string &word, int curIdx) {
        if (curIdx == word.size())
            return true;

        bool flag = false;
        if (!flag && curRow+1 < board.size() && board[curRow+1][curCol] == word[curIdx]) { // bottom
            board[curRow+1][curCol] = '.'; // mark as visited
            flag = exist(board, curRow + 1, curCol, word, curIdx + 1);
            board[curRow+1][curCol] = word[curIdx]; // recover
        }
        if (!flag && curRow-1 >= 0 && board[curRow-1][curCol] == word[curIdx]) { // up
            board[curRow-1][curCol] = '.';
            flag = exist(board, curRow-1, curCol, word, curIdx + 1);
            board[curRow-1][curCol] = word[curIdx];
        }
        if (!flag && curCol-1 >= 0 && board[curRow][curCol-1] == word[curIdx]) { // left
            board[curRow][curCol-1] = '.';
            flag = exist(board, curRow, curCol-1, word, curIdx + 1);
            board[curRow][curCol-1] = word[curIdx];
        }
        if (!flag && curCol+1 < board.front().size() && board[curRow][curCol+1] == word[curIdx]) { // right
            board[curRow][curCol+1] = '.';
            flag = exist(board, curRow, curCol+1, word, curIdx + 1);
            board[curRow][curCol+1] = word[curIdx];
        }

        return flag;
    }
};

int main()
{
    cout << "79. Word Search" << endl;

    return 0;
}


#endif
