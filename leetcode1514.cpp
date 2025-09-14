#include<bits/stdc++.h>
#include<iostream>
using namespace std;
double maxProbability(int n,vector<vector<int>>&edges,vector<double>&succProb,int start,int end){
    vector<vector<pair<int ,double>>>adj(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        double prob=succProb[i];
        adj[u].push_back({v,prob});
    }
    vector<double>prob(n,0.0);
    prob[start]=1.0;
    priority_queue<pair<double,int>>pq;
    pq.push({1.0,start});

    while(!pq.empty()){
        auto[currProb,u]=pq.top();
        pq.pop();
        if(u==end) return currProb;

        for(auto &[v,edgeProb]:adj[u]){
            double newProb=currProb*edgeProb;
            if(newProb>prob[v]){
                prob[v]=newProb;
            pq.push({newProb,v});
            }
        }
    }
    return 0.0;
}
int main(){
      int n = 3;
    vector<vector<int>> edges = {{0,1}, {1,2}, {0,2}};
    vector<double> succProb = {0.5, 0.5, 0.3};
    int start = 0, end = 2;

    double ans = maxProbability(n, edges, succProb, start, end);
    cout << "Maximum probability from " << start << " to " << end << " = " << ans << endl;

    return 0;
}
