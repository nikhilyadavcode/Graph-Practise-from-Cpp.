#include <bits/stdc++.h>
using namespace std;

int minimumEffortpath(vector<vector<int>>& heights) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int n = heights.size();       
    int m = heights[0].size();     

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};


    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
    effort[0][0] = 0;

    pq.push({0, 0, 0});  

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int currEffort = top[0];
        int i = top[1];
        int j = top[2];

        if (i == n - 1 && j == m - 1) {
            return currEffort;
        }

        for (int k = 0; k < 4; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];

            if (newi >= 0 && newi < n && newj >= 0 && newj < m) {
                int diff = abs(heights[i][j] - heights[newi][newj]);
                int newEffort = max(currEffort, diff);

                if (newEffort < effort[newi][newj]) {
                    effort[newi][newj] = newEffort;
                    pq.push({newEffort, newi, newj});
                }
            }
        }
    }

    return 0; 
}

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << "Minimum Effort Path = " << minimumEffortpath(heights) << endl;
    return 0;
}
