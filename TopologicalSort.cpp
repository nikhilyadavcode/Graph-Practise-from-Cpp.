#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void DFSTopo(int u,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st){
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            DFSTopo(v,adj,visited,st);
        }
    }
    st.push(u);
}

vector<int>topologistSort(int V,vector<vector<int>>&adj){
    vector<bool>visited(V,false);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFSTopo(i,adj,visited,st);
        }
    }
    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
int main(){
    int V=6;
    vector<vector<int>>adj(V);

    adj[5].push_back(0);
    adj[5].push_back(2);

    adj[4].push_back(0);
    adj[4].push_back(1);

    adj[2].push_back(3);

    adj[3].push_back(1);

    vector<int>topo=topologistSort(V,adj);

    cout<<"Topologist sorting is:";

    for(int node:topo){
        cout<<node<<" ";
    }

    
}