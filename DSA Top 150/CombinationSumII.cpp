#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index, vector<int>& candidates, int target, vector<int>& temp) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates at the same level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            solve(i + 1, candidates, target - candidates[i], temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();

        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        solve(0, candidates, target, temp);

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = obj.combinationSum2(candidates, target);

    for (auto combination : result) {
        cout << "[ ";
        for (int x : combination) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}