#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>Dijkstra(int V,vector<vector<pair<int,int>>>&adj,int src){
    vector<int>dist(V,1e9);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0,src});

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
    return dist;

}
int main(){
    int V=6;
    vector<vector<pair<int,int>>>adj(V);
    adj[0].push_back({1,2});
    adj[0].push_back({2,4});

    adj[1].push_back({2,1});
    adj[1].push_back({3,7});

    adj[2].push_back({4,3});

    adj[3].push_back({5,1});

    adj[4].push_back({3,2});
    adj[4].push_back({5,5});
   

    vector<int>dist=Dijkstra(V,adj,0);
    cout<<"The shortest distance from a Node:"<<endl;
    for(int i=0;i<V;i++){
        cout<<"Node"<<i<<":"<<dist[i]<<endl;
    }

}