#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, int dest, vector<vector<int>>& adj, vector<bool>& visited) {
    if (node == dest) return true;
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, dest, adj, visited)) 
                return true;
        }
    }
    return false;
}

bool validPath(int V, vector<vector<int>>& adj, int src, int dest) {
    vector<bool> visited(V, false);
    return dfs(src, dest, adj, visited);
}

int main() {
    int V = 6;
    int src = 0;
    int dest = 5;

    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);

    adj[2].push_back(0);

    adj[3].push_back(4);
    adj[3].push_back(5);

    adj[4].push_back(3);
    adj[4].push_back(5);

    adj[5].push_back(3);
    adj[5].push_back(4); // correction: earlier tumne 2 baar 3 dala tha

    if (validPath(V, adj, src, dest)) 
        cout << "Path exists\n";
    else 
        cout << "No path\n";

    return 0;
}
