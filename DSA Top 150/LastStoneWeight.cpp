#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int &stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            pq.push(abs(a - b));
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    Solution obj;
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    cout << obj.lastStoneWeight(stones) << endl;

    return 0;
}