#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isBipartite( vector<vector<int>> &graph){
    int v=graph.size();
    vector<int>color(v,-1);

    for(int start=0;start<v;start++){
        if(color[start]==-1){
            queue<int>q;
            q.push(start);
            color[start]=0;

            while(!q.empty()){
                int node=q.front();
                q.pop();

            for(int neighbor:graph[node]){
                if(color[neighbor]==-1){
                    color[neighbor]=1-color[node];
                    q.push(neighbor);
                }
                else if(color[neighbor]==color[node]){
                    return false;
                }
            }
            }
        }
    }
    return true;
}
int main(){
     vector<vector<int>> graph = {
        {1, 3}, // neighbors of 0
        {0, 2}, // neighbors of 1
        {1, 3}, // neighbors of 2
        {0, 2}  // neighbors of 3
    };

    if (isBipartite(graph)) {
        cout <<  "Graph is Bipartite";
    } else {
        cout << "Graph is NOT Bipartite";
    }

}