#include<iostream>
#include<vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            DFS(neighbour, adj, visited);
        }
    }
}

bool isConnected(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    DFS(0, adj, visited);  

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false;  
    }
}
    return true;
}
int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Graph edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);
    
    adj[4].push_back(5);
    adj[5].push_back(4);

    if (isConnected(V, adj))
        cout << "Connected Graph";
    else
        cout << "Disconnected Graph";

    return 0;
}
