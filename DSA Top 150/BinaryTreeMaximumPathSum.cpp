#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxSum = 0;

    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche = root->val + l + r;
        int koiekacha = max(l, r) + root->val;
        int onlyrootacha = root->val;

        maxSum = max({maxSum, neeche, onlyrootacha, koiekacha});

        return max(koiekacha, onlyrootacha);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};

int main() {

    // Tree:
    //
    //        -10
    //        / \
    //       9   20
    //          /  \
    //         15   7

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    int result = obj.maxPathSum(root);

    cout << "Maximum Path Sum: " << result << endl;

    return 0;
}