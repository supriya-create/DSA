#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (sum < target) {
                i++;
            }
            else if (sum > target) {
                j--;
            }
            else {
                return {i + 1, j + 1};   // 1-based indexing
            }
        }

        return {};
    }
};

int main() {
    Solution obj;

    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = obj.twoSum(numbers, target);

    if (!ans.empty()) {
        cout << "Indices: " << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}