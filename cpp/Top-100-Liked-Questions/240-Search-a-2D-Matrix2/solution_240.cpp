/*
 * 240. Search a 2D Matrix II
 */


#include "common.h"


#if LEET_CODE == 240

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        int rows = matrix.size();
        int cols = matrix.front().size();
        int i = 0, j = cols-1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] > target)
                j --;
            else if (matrix[i][j] < target)
                i ++;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    cout << "240. Search a 2D Matrix II" << endl;

    return 0;
}


#endif
