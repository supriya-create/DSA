#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        // Count frequency of each number
        unordered_map<int, int> mp;

        for (int &num : nums) {
            mp[num]++;
        }

        // bucket[i] contains numbers appearing i times
        vector<vector<int>> bucket(n + 1);

        for (auto &it : mp) {
            int element = it.first;
            int freq = it.second;

            bucket[freq].push_back(element);
        }

        vector<int> result;

        // Start from highest frequency
        for (int i = n; i >= 0 && k > 0; i--) {

            while (!bucket[i].empty() && k > 0) {

                result.push_back(bucket[i].back());
                bucket[i].pop_back();

                k--;
            }
        }

        return result;
    }
};

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution obj;

    vector<int> result = obj.topKFrequent(nums, k);

    cout << "[ ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << "]" << endl;

    return 0;
}