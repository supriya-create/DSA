#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Last node of every level
                if (i == size - 1) {
                    ans.push_back(node->val);
                }

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};

int main() {

    // Tree:
    //
    //        1
    //       / \
    //      2   3
    //       \   \
    //        5   4

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;

    vector<int> result = obj.rightSideView(root);

    cout << "Right Side View: ";

    for (int val : result) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}