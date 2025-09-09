#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int>topologistSort(int V,vector<vector<int>>&adj){

    vector<int>indegree(V,0);

    for(int i=0;i<V;i++){
        for(int v:adj[i]){
            indegree[v]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        topo.push_back(u);

        for(int V:adj[u]){
            indegree[V]-- ;
            if(indegree[V]==0){
                q.push(V);
            }
        }
    }
    if((int)topo.size()!=V){
        cout<<"cycle detected! No valid opologiscal order";
        return {};
    }
    return topo;
}
int main(){
    int V=4;

    vector<vector<int>>adj(V);

    adj.push_back({1,0});
    adj.push_back({2,0});
    adj.push_back({3,1});
    adj.push_back({3,2});

    vector<int>topo=topologistSort(V,adj);
    cout<<"Topologist Sort Using BFS:";

    for(int node:topo){
        cout<<node<<" ";
    }
    cout<<endl;
}