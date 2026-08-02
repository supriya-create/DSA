#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int lastsmall = INT_MIN;
        int cnt = 0;
        int longest = 1;

        for (int i = 0; i < n; i++) {

            if (nums[i] - 1 == lastsmall) {
                cnt++;
                lastsmall = nums[i];
            }

            else if (lastsmall != nums[i]) {
                cnt = 1;
                lastsmall = nums[i];
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Longest Consecutive Sequence Length: "
         << obj.longestConsecutive(nums);

    return 0;
}