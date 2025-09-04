#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front(); 
            q.pop();
            
            if (node == destination) return true;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    int n = 6;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}
    };
    int source = 0, destination = 5;

    bool result = sol.validPath(n, edges, source, destination);
    if (result) 
        cout << "Path exists between " << source << " and " << destination << endl;
    else 
        cout << "No path exists between " << source << " and " << destination << endl;

    return 0;
}
