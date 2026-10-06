#include <iostream>
#include <algorithm>
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
    int dfs(TreeNode* root, int maxi) {
        int count = 0;

        if (root == NULL)
            return 0;

        if (root->val >= maxi) {
            count = 1;
            maxi = root->val;
        }

        count += dfs(root->left, maxi);
        count += dfs(root->right, maxi);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};

int main() {

    // Tree:
    //
    //        3
    //       / \
    //      1   4
    //     /   / \
    //    3   1   5

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(3);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution obj;

    int result = obj.goodNodes(root);

    cout << "Number of Good Nodes: " << result << endl;

    return 0;
}