#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>>&times,int n,int k){
    vector<vector<pair<int,int>>>adj(n+1);
    for(auto &edge:times){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});

    }
    vector<int>dist(n+1,1e9);
    dist[k]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,k});
    while(!pq.empty()){
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();

        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(d+w<dist[v]){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==1e9) return -1;
        ans=max(ans,dist[i]);
    }
    return ans;
}
int main(){
    vector<vector<int>> times = {
        {2,1,1}, {2,3,1}, {3,4,1}
    };
    int n = 4, k = 2;
    cout << networkDelayTime(times, n, k) << endl;
}
