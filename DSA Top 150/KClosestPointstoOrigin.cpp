#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for (auto p : points) {
            int d = p[0] * p[0] + p[1] * p[1];
            pq.push({d, p});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> points = {
        {1, 3}, {-2, 2}, {5, 8}, {0, 1}
    };

    int k = 2;

    vector<vector<int>> ans = obj.kClosest(points, k);

    for (auto p : ans) {
        cout << "[" << p[0] << ", " << p[1] << "]" << endl;
    }

    return 0;
}