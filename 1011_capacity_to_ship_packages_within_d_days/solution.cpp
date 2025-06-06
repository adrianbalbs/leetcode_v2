#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left <= right) {
            int weight = left + (right - left) / 2;
            if (canShip(weights, days, weight)) {
                right = weight - 1;
            } else {
                left = weight + 1;
            }
        }
        return left;
    }

    bool canShip(vector<int>& weights, int days, int ship_weight) {
        int curr = 0, d = 1;
        for (auto &w : weights) {
            if (curr + w > ship_weight) {
                d++;
                curr = 0;
            }
            curr += w;
        }
        return d <= days;
    }
};

