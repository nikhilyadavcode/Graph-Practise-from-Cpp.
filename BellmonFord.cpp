
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

struct Edge {
    int u, v;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, src;
    if (!(cin >> n >> m >> src)) {
        cerr << "Bad input\n";
        return 0;
    }

    vector<Edge> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<ll> dist(n, INF);
    dist[src] = 0;

 
    for (int i = 1; i <= n-1; ++i) {
        bool changed = false;
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break; 
    }
    bool neg_cycle = false;
    for (auto &e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            neg_cycle = true;
            break;
        }
    }

    if (neg_cycle) {
        cout << "Graph contains a negative-weight cycle reachable from source.\n";
    } else {
        cout << "No negative-weight cycle reachable from source.\n";
        cout << "Distances from source " << src << ":\n";
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) cout << "node " << i << ": INF\n";
            else cout << "node " << i << ": " << dist[i] << '\n';
        }
    }

    return 0;
}
