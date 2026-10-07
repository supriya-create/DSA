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
    int dia = 0;

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        dia = max(dia, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return dia;
    }
};

int main() {

    // Tree:
    //
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    int result = obj.diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree: " << result << endl;

    return 0;
}