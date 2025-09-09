#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
bool TopologistSort(int V,vector<vector<int>>&adj){
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(int u:adj[i]){
            indegree[u]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }
    int count=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        count++;

        for(int v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }
    return (count==V);
}
int main(){
    int V = 6;
    vector<vector<int>> adj(V);

    adj[4].push_back(0);
    adj[4].push_back(1);

    adj[5].push_back(0);
    adj[5].push_back(2);

    adj[2].push_back(3);

    adj[3].push_back(1);

    cout << (TopologistSort(V, adj) ? 
                "No Cycle (Topological order possible)" : 
                "Cycle Detected");
    cout << endl;

    vector<vector<int>> adj2(V);
    adj2[0].push_back(1);
    adj2[1].push_back(2);
    adj2[2].push_back(3);

    cout << (TopologistSort(V, adj2) ? 
                "No Cycle (Topological order possible)" : 
                "Cycle Detected");
    cout << endl;
}