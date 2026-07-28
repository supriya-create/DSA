#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int>, vector<string>> mp;

        for (string word : strs) {

            vector<int> count(26, 0);

            for (char ch : word) {
                count[ch - 'a']++;
            }

            mp[count].push_back(word);
        }

        vector<vector<string>> ans;

        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution obj;

    vector<vector<string>> result = obj.groupAnagrams(strs);

    for (auto &group : result) {
        cout << "[ ";

        for (string word : group) {
            cout << word << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}