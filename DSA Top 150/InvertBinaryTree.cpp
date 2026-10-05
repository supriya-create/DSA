#include <iostream>
#include <utility>
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
    TreeNode* invertTree(TreeNode* root) {

        if (root == NULL)
            return NULL;

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Inorder traversal
void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    // Create tree:
    //
    //        4
    //       / \
    //      2   7
    //     / \ / \
    //    1  3 6  9

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution obj;

    cout << "Before Inversion (Inorder): ";
    inorder(root);
    cout << endl;

    obj.invertTree(root);

    cout << "After Inversion (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}