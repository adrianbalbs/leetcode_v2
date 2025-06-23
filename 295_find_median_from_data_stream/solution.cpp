#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> bottom_half;
    priority_queue<int, vector<int>, greater<>> top_half;

  public:
    MedianFinder() {}

    void addNum(int num) {
        if (!top_half.empty() && num > top_half.top()) {
            top_half.push(num);
        } else {
            bottom_half.push(num);
        }
        if (bottom_half.size() > top_half.size() + 1) {
            top_half.push(bottom_half.top());
            bottom_half.pop();
        }
        if (top_half.size() > bottom_half.size()) {
            bottom_half.push(top_half.top());
            bottom_half.pop();
        }
    }

    double findMedian() {
        int size = top_half.size() + bottom_half.size();
        if (size % 2 == 0) {
            return (bottom_half.top() + top_half.top()) / 2.0;
        } else {
            return bottom_half.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
