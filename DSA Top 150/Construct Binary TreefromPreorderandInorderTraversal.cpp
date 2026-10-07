#include <iostream>
#include <vector>
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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int start, int end, int& idx) {

        if (start > end)
            return NULL;

        int rootVal = preorder[idx];

        int i = start;

        for (; i <= end; i++) {
            if (inorder[i] == rootVal)
                break;
        }

        idx++;

        TreeNode* root = new TreeNode(rootVal);

        root->left = solve(preorder, inorder, start, i - 1, idx);

        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;

        return solve(preorder, inorder, 0, n - 1, idx);
    }
};

// Print tree in preorder
void printPreorder(TreeNode* root) {
    if (root == NULL)
        return;

    cout << root->val << " ";

    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Constructed Tree (Preorder): ";

    printPreorder(root);

    cout << endl;

    return 0;
}