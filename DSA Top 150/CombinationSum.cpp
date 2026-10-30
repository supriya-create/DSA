#include <iostream>
#include <vector>
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

            if (candidates[i] > target)
                continue;

            temp.push_back(candidates[i]);

            solve(i, candidates, target - candidates[i], temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();

        vector<int> temp;
        solve(0, candidates, target, temp);

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = obj.combinationSum(candidates, target);

    for (auto combination : result) {
        cout << "[ ";
        for (int x : combination) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}