#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numSt;
        stack<string> strSt;

        string curr = "";
        int num = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '[') {
                numSt.push(num);
                strSt.push(curr);
                num = 0;
                curr = "";
            }

            else if (ch == ']') {
                string temp = strSt.top();
                strSt.pop();

                int k = numSt.top();
                numSt.pop();

                while (k--) {
                    temp += curr;
                }

                curr = temp;
            }

            else {
                curr += ch;
            }
        }

        return curr;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter encoded string: ";
    cin >> s;

    cout << "Decoded string: " << obj.decodeString(s) << endl;

    return 0;
}