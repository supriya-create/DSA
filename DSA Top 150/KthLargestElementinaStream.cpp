#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K = k;

        for (int &num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > K) {
            pq.pop();
        }

        return pq.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};

    KthLargest obj(3, nums);

    cout << obj.add(3) << endl;  // 4
    cout << obj.add(5) << endl;  // 5
    cout << obj.add(10) << endl; // 5
    cout << obj.add(9) << endl;  // 8
    cout << obj.add(4) << endl;  // 8

    return 0;
}