#include<iostream>
#include<vector>
using namespace std;

bool DFSCycleDirected(int u, vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1; 
    for (int v : adj[u]) {
        if (color[v] == 1) return true; 
        if (color[v] == 0 && DFSCycleDirected(v, adj, color)) return true;
    }
    color[u] = 2; 
    return false;
}

bool hasCycleDirected(int V, vector<vector<int>>& adj) {
    vector<int> color(V, 0);
    for (int i = 0; i < V; i++) {
        if (color[i] == 0 && DFSCycleDirected(i, adj, color))
            return true;
    }
    return false; 
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0); 
    adj[2].push_back(3);

    cout << (hasCycleDirected(V, adj) ? "Cycle detected (directed)\n" : "No Cycle\n");

    return 0;
}
