#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return (long)a * (long)b; }},
            {"/", [](int a, int b) { return a / b; }}
        };

        for (string &token : tokens) {

            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = mp[token](a, b);
                st.push(result);

            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

int main() {
    vector<string> tokens = {
        "2", "1", "+", "3", "*"
    };

    Solution obj;

    int result = obj.evalRPN(tokens);

    cout << "Result: " << result << endl;

    return 0;
}