#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    void serialize(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "# ";
            return;
        }

        s += to_string(root->val) + " ";

        serialize(root->left, s);
        serialize(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serialize(root, s);
        return s;
    }

    TreeNode* deserializeTree(stringstream& ss) {
        string val;

        if (!(ss >> val)) {
            return NULL;
        }

        if (val == "#") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = deserializeTree(ss);
        root->right = deserializeTree(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeTree(ss);
    }
};

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;

    string data = codec.serialize(root);

    cout << "Serialized: " << data << endl;

    TreeNode* newRoot = codec.deserialize(data);

    cout << "Deserialization successful!" << endl;

    return 0;
}