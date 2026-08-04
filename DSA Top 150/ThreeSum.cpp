#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void twoSum(vector<int>& nums, int target, int left, int right) {
        while (left < right) {

            if (nums[left] + nums[right] > target) {
                right--;
            }
            else if (nums[left] + nums[right] < target) {
                left++;
            }
            else {
                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1])
                    left++;

                while (left < right && nums[right] == nums[right - 1])
                    right--;

                result.push_back({-target, nums[left], nums[right]});

                left++;
                right--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        if (n < 3)
            return {};

        result.clear();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int n1 = nums[i];
            int target = -n1;

            twoSum(nums, target, i + 1, n - 1);
        }

        return result;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = obj.threeSum(nums);

    cout << "Triplets are:\n";

    for (auto &triplet : ans) {
        cout << "[ ";
        for (int x : triplet)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}