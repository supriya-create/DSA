#include <iostream>
#include <algorithm>
#include <cmath>
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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int r = height(root->right);
        int l = height(root->left);

        // If either subtree is already unbalanced
        if (l == -1 || r == -1) {
            return -1;
        }

        // Check current node
        if (abs(r - l) > 1) {
            return -1;
        }

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

int main() {

    // Balanced Tree:
    //
    //        3
    //       / \
    //      9  20
    //         / \
    //        15  7

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    if (obj.isBalanced(root)) {
        cout << "Tree is Balanced" << endl;
    } else {
        cout << "Tree is Not Balanced" << endl;
    }

    return 0;
}