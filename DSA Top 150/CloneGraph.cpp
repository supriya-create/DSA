#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for (int i = 0; i < node->neighbors.size(); i++) {
            Node* neighbor = node->neighbors[i];
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

int main() {
    // Create original graph
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // Add edges
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Solution obj;

    // Clone graph
    Node* cloned = obj.cloneGraph(n1);

    // Print cloned graph using BFS
    unordered_set<Node*> visited;
    queue<Node*> q;

    q.push(cloned);
    visited.insert(cloned);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->val << " -> ";

        for (int i = 0; i < curr->neighbors.size(); i++) {
            Node* neighbor = curr->neighbors[i];

            cout << neighbor->val << " ";

            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }

        cout << endl;
    }

    return 0;
}