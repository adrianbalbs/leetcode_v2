#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int ans = 0;
        for (int right = 1; right < prices.size(); right++) {
            if (prices[right] - prices[right - 1] >= 0) {
                ans += prices[right] - prices[right - 1];
            } 
        }
        return ans;
    }
};
