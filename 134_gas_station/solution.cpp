#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    if (accumulate(cost.begin(), cost.end(), 0) >
        accumulate(gas.begin(), gas.end(), 0)) {
      return -1;
    }
    int curr_gas = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++) {
      curr_gas += gas[i] - cost[i];
      if (curr_gas < 0) {
        curr_gas = 0;
        start = i + 1;
      }
    }
    return start;
  }
};
