/*
 * 121. Best Time to Buy and Sell Stock
 */


#include "common.h"


#if LEET_CODE == 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = 0x7fffffff;
        for (int i=0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

int main()
{
    cout << "121. Best Time to Buy and Sell Stock" << endl;

    return 0;
}


#endif
