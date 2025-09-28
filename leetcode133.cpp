#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
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
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        if (mp.find(node) != mp.end()) 
            return mp[node]; // already cloned

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

// Helper function to print graph (BFS)
void printGraph(Node* node) {
    if (!node) return;

    unordered_map<Node*, bool> visited;
    vector<Node*> q;
    q.push_back(node);
    visited[node] = true;

    while (!q.empty()) {
        Node* curr = q.back();
        q.pop_back();

        cout << "Node " << curr->val << " -> ";
        for (auto neigh : curr->neighbors) {
            cout << neigh->val << " ";
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push_back(neigh);
            }
        }
        cout << endl;
    }
}

int main() {
    // Build example graph: 1--2, 2--3, 3--4, 4--1
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    cout << "Original Graph:" << endl;
    printGraph(n1);

    Solution sol;
    Node* cloned = sol.cloneGraph(n1);

    cout << "\nCloned Graph:" << endl;
    printGraph(cloned);

    return 0;
}
