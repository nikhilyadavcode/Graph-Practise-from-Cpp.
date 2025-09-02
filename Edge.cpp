#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int wt;

    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        wt = w;
    }
};

int main() {
    int V = 5;
    vector<vector<Edge>> graph(V);

    // Adding edges
    graph[0].push_back(Edge(0, 1, 5));

    graph[1].push_back(Edge(1, 0, 5));
    graph[1].push_back(Edge(1, 2, 1));
    graph[1].push_back(Edge(1, 3, 3));

    graph[2].push_back(Edge(2, 1, 1));
    graph[2].push_back(Edge(2, 3, 1));
    graph[2].push_back(Edge(2, 4, 4));

    graph[3].push_back(Edge(3, 1, 3));
    graph[3].push_back(Edge(3, 2, 1));

    graph[4].push_back(Edge(4, 2, 2));

    // Print all edges connected to vertex 2
    for (int i = 0; i < graph[2].size(); i++) {
        Edge e = graph[2][i];
        cout << e.dest << endl;
    }

    return 0;
}
