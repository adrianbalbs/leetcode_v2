#include <array>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        array<int, 26> freq;

        for (auto &c : tasks) {
            freq[c - 'A']++;
        }
        priority_queue<int> pq;
        for (auto cnt : freq)
            if (cnt > 0)
                pq.push(cnt);

        int ans = 0;
        while (!pq.empty()) {
            int cycles = n + 1;
            int task_count = 0;
            vector<int> remaining;
            while (cycles-- && !pq.empty()) {
                int count = pq.top();
                pq.pop();
                if (count > 1) {
                    remaining.push_back(count - 1);
                }
                task_count++;
            }
            for (int &r : remaining)
                pq.push(r);
            ans += pq.empty() ? task_count : n + 1;
        }

        return ans;
    }
};
