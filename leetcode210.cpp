
                        //   USING BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); // adjacency list
        vector<int> indegree(numCourses, 0);   // indegree array

    
        for (auto &p : prerequisites) {
            int a = p[0], b = p[1]; 
            graph[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
       
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo; 
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (int v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if ((int)topo.size() != numCourses) {
            return {};
        }
        return topo;
    }
};

int main() {
    Solution sol;

    int numCourses = 4;
    vector<vector<int>> prerequisites;
    prerequisites.push_back({1,0});
    prerequisites.push_back({2,0});
    prerequisites.push_back({3,1});
    prerequisites.push_back({3,2});

    vector<int> order = sol.findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "Cycle detected! No valid topological order exists.\n";
    } else {
        cout << "One possible course order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
