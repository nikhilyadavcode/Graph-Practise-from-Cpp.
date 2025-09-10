#include<iostream>
#include<vector>
using namespace std;
void DFS(int node,vector<vector<int>>&graph,vector<vector<int>>&result,vector<int>&path){
    path.push_back(node);
    int destination=graph.size()-1;
    if(node==destination){
        result.push_back(path);
    }
    else{
        for(int next:graph[node]){
            DFS(next,graph,result,path);
        }
    }
    path.pop_back();
}
vector<vector<int>>allPathsSourceTarget(vector<vector<int>>&graph){
    vector<vector<int>>result;
    vector<int>path;
    DFS(0,graph,result,path);
    return result;
}
int main(){
    int V=4;
    vector<vector<int>>graph(V);

    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(3);

    graph[2].push_back(3);
    vector<vector<int>> paths = allPathsSourceTarget(graph);
     cout << "All paths from 0 to " << graph.size()-1 << ":\n";
    for (auto &path : paths) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
}
}