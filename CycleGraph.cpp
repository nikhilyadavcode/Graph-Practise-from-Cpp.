// #include<bits/stdc++.h>
// using namespace std;
// bool DFSDIR(int u,vector<vector<int>>&adj,vector<int>&color){
// color[u]=true;
// for(int V:adj[u]){
//     if(color[V]==false){
//         if(DFSDIR(V,adj,color)) return true;
//     }
//     else if(color[V]==true){
//         return true;
//     }
// }
// color[u]=2;
// return false;

// }
// bool hasCycleDirected(int V,vector<vector<int>>& adj){
//     vector<int>color(V,false);
//     for(int i=0;i<V;i++){
//         if(color[i]==false && DFSDIR(i,adj,color)) return true;
//     }
//     return false;
// }
// int main(){
//     int V=5;
//     vector<vector<int>>adj(V);
//     adj[0].push_back(1);

//     adj[1].push_back(2);

//     adj[2].push_back(3);

//     adj[3].push_back(1);\

//      cout << (hasCycleDirected(V, adj) ? "Cycle detected\n" : "No cycle\n");
// }



#include<bits/stdc++.h>
using namespace std;
bool DFSDIR(int u,vector<vector<int>>&UndirectEdges,vector<int>&node){
node[u]=true;
for(int V:UndirectEdges[u]){
   if(node[V]==false){
     if(node[V]==false && DFSDIR(V,UndirectEdges,node)) return true;
   }
    else if (node[V]==true) {
        return true;
    }
}
node[u]=2;
return false;

}

bool hasCycleDirected(int V,vector<vector<int>>&UndirectEdges){
    vector<int>node(V,false);

    for(int i=0;i<V;i++){
        if(node[i]==false && DFSDIR(i,UndirectEdges,node)) return true;
    }
    return false;
}
int main(){
    int V=5;
    vector<vector<int>>UndirectEdges(V);

    UndirectEdges[0].push_back(1);

    UndirectEdges[1].push_back(2);

    UndirectEdges[2].push_back(3);

    UndirectEdges[3].push_back(1);

      cout <<(hasCycleDirected(V, UndirectEdges) ? "Cycle detected\n" : "No cycle\n");
}