#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void solve(int i, vector<int>& nums, vector<int>& temp) {
        if (i >= nums.size()) {
            result.push_back(temp);
            return;
        }

        // Include the current element
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp);

        // Exclude the current element
        temp.pop_back();
        solve(i + 1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();  // Reset for repeated calls
        vector<int> temp;
        solve(0, nums, temp);
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = obj.subsets(nums);

    for (auto subset : ans) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}