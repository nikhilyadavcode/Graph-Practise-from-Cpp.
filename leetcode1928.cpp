#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        
        // Graph adjacency list: node -> (neighbor, time)
        vector<vector<pair<int,int>>> graph(n);
        for(auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        
        // minCost[node][time] = minimum cost to reach node at 'time'
        vector<vector<int>> minCost(n, vector<int>(maxTime+1, INT_MAX));
        
        // PQ: (cost, time, node)
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        
        pq.push({passingFees[0], 0, 0});
        minCost[0][0] = passingFees[0];
        
        while(!pq.empty()) {
            auto [cost, time, node] = pq.top();
            pq.pop();
            
            if(node == n-1) return cost; // destination reached
            
            for(auto &[nbr, t] : graph[node]) {
                int newTime = time + t;
                int newCost = cost + passingFees[nbr];
                if(newTime <= maxTime && newCost < minCost[nbr][newTime]) {
                    minCost[nbr][newTime] = newCost;
                    pq.push({newCost, newTime, nbr});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Example test case
    int maxTime = 30;
    vector<vector<int>> edges = {{0,1,10}, {1,2,10}, {0,2,25}};
    vector<int> passingFees = {5, 1, 2};

    int result = sol.minCost(maxTime, edges, passingFees);

    if(result == -1)
        cout << "Destination cannot be reached within time limit." << endl;
    else
        cout << "Minimum cost to reach destination: " << result << endl;

    return 0;
}
