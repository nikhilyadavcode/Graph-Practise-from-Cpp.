#include<iostream>
#include<vector>
using namespace std;
void DFS(int start,vector<int>adj[],vector<bool>&visited){
    visited[start]=true;

    cout<<start<<" ";

    for(int neighbour:adj[start]){
        if(!visited[neighbour]){
            DFS(neighbour,adj,visited);
        }
    }
}
int main(){
    int V=7;
    vector<int>adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(5);

    adj[4].push_back(2);
    adj[4].push_back(3);
    adj[4].push_back(5);

    adj[5].push_back(3);
    adj[5].push_back(4);
    adj[5].push_back(6);

    adj[6].push_back(5);

    vector<bool>visited(V,false);
    cout<<"DFS Traversal from node 0:";

    DFS(0,adj,visited);

}