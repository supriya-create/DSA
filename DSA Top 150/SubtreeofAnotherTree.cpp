#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p == NULL || q == NULL)
            return p == q;

        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot == NULL)
            return true;

        if(root == NULL)
            return false;

        if(isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main() {

    // Main tree
    //
    //         3
    //        / \
    //       4   5
    //      / \
    //     1   2

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(4);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);


    // Subtree
    //
    //       4
    //      / \
    //     1   2

    TreeNode* subRoot = new TreeNode(4);

    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);


    Solution obj;

    if(obj.isSubtree(root, subRoot))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}