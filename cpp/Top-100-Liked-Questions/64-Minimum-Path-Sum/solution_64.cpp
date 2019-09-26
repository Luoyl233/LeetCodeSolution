/*
 * 64. Minimum Path Sum
 */


#include "common.h"


#if LEET_CODE == 64

// TODO: Optimize
class Solution {
    public int minPathSum(int[][] grid) {
         int sum = 0;

        int m = grid.length;
        int n = grid[0].length;
        int f[][] = new int [m+1][n+1];
        for(int i=0; i <= m; i++) {
            for(int j=0; j <= n; j++)
                f[i][j] = Integer.MAX_VALUE;
        }
        f[m][n] = 0;
        f[m][n-1] = 0;
        f[m-1][n] = 0;

        for(int i=m-1; i >= 0; i--) {
            for(int j=n-1; j >= 0; j--) {
                f[i][j] = Math.min(f[i][j+1], f[i+1][j]) + grid[i][j];
            }
        }

//        for(int i=0; i <= m; i++) {
//        	for(int j=0; j <= n; j++)
//        		System.out.print(f[i][j] + " ");
//        	System.out.println();
//        }

        sum = f[0][0];
        return sum;
    }
}

int main()
{
    cout << "64. Minimum Path Sum" << endl;

    return 0;
}


#endif
