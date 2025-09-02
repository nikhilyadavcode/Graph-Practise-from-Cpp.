#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool HasPath(int src,vector<int>adj[],vector<bool>&visited,int dest){
    if(src==dest){
        return true;
    }
    for(int neighbor:adj[src]){
        if(!visited[neighbor]){
             visited[neighbor] = true; 
            if(HasPath(neighbor,adj,visited,dest)){
                return true;

            }
        }
    }
    return false;
}
int main(){
    int V=7;
    int src=0;
    int dest=5;
    vector<int>adj[V];

    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(3);
    adj[1].push_back(0);

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

     if (HasPath(src,adj,visited,dest)) {
        cout << "Path exists from " << src << " to " << dest << endl;
    } else {
        cout << "No path exists from " << src << " to " << dest << endl;
    }

    return 0;
}



