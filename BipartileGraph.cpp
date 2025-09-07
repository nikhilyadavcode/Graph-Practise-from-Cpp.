#include<iostream>
#include<vector>
#include<queue>
using namespace std;
    bool isBipartile(int V,vector<vector<int>>&adj){
        vector<int>color(V,-1);

        for(int start=0; start<V;start++){
            if(color[start]==-1){
                queue<int>q;
                q.push(start);
                color[start]=0;

                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                
                for(int neighbor:adj[node]){
                    if(color[neighbor]==-1){
                        color[neighbor]=1-color[node];
                        q.push(neighbor);
                    }
                    else if(color[neighbor]==color[node]){
                        return false;
                    }
                }
            }

        }
    }
        return true;
    }
int main(){
    int V=5;
    vector<vector<int>>adj(V);

    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(1);
    adj[3].push_back(4);

    adj[4].push_back(2);
    adj[4].push_back(3);

    if(isBipartile(V,adj)){
        cout<<"Graph is Bipartile";
    }
    else{
        cout<<"Graph is not Bipartile";
    }
}