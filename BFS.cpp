#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void BFS(int start,vector<vector<int>>&adj,int V){

    vector<bool>visited(V,false);

    queue<int>q;

    visited[start]=true;
    q.push(start);

    cout<<"BFS starting from node"<<start<<" ";

    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";


    for(int i=0;i<adj[node].size();i++){
        int neighbour=adj[node][i];

        if(!visited[neighbour]){
            visited[neighbour]=true;
            q.push(neighbour);
        }
    }
    }
}
int main(){
    int V=7;
    vector<vector<int>>adj(V);

    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(3);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[3].push_back(6);

    adj[4].push_back(2);
    adj[4].push_back(3);
    adj[4].push_back(5);

    adj[5].push_back(3);
    adj[5].push_back(4);
    adj[5].push_back(6);

    adj[6].push_back(3);
    adj[6].push_back(5);

    BFS(0,adj,V);

}