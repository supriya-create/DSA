#include <iostream>
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
    bool check(TreeNode* root, long long low, long long high) {
        if (root == NULL)
            return true;

        if (root->val <= low || root->val >= high)
            return false;

        return check(root->left, low, root->val) &&
               check(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {

    // Valid BST:
    //
    //        5
    //       / \
    //      3   7
    //     / \ / \
    //    2  4 6  8

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    if (obj.isValidBST(root)) {
        cout << "Valid BST" << endl;
    } else {
        cout << "Invalid BST" << endl;
    }

    return 0;
}