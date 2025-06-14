#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap {
private:
  unordered_map<string, vector<pair<int, string>>> map;

  string upper_bound(vector<pair<int, string>> &list, int key) {
    int lo = 0;
    int hi = list.size() - 1;
    string ans = "";
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (list[mid].first > key) {
        hi = mid - 1;
      } else {
        ans = list[mid].second;
        lo = mid + 1;
      }
    }
    return ans;
  }

public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    map[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    if (!map.contains(key)) {
      return "";
    }
    return upper_bound(map[key], timestamp);
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
