/**
 * 48. Rotate Image
 */

#include "common.h"

#if LEET_CODE == 48

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int layer=0; layer < n/2; layer++) {
            int layerLen = n - layer * 2 - 1;
            // NOTE: i < layerLen
            for (int i=0; i < layerLen; i++) {
                swap(matrix[layer][layer+i], matrix[layer+i][layer+layerLen]);
                swap(matrix[layer][layer+i], matrix[layer+layerLen][layer+layerLen-i]);
                swap(matrix[layer][layer+i], matrix[layer+layerLen-i][layer]);
            }
        }
    }
};


#endif
