#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        string str = "";

        // Remove special characters and convert to lowercase
        for(char ch : s) {
            if(isalnum(ch)) {
                str += tolower(ch);
            }
        }

        int i = 0;
        int j = str.size() - 1;

        while(i < j) {
            if(str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if(obj.isPalindrome(s))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}