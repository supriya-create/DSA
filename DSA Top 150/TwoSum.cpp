#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int more = target - num;

            if (mpp.find(more) != mpp.end()) {
                return {mpp[more], i};
            }

            mpp[num] = i;
        }

        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}