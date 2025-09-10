#include<iostream>
#include<vector>
using namespace std;
void printAllPaths(vector<vector<int>>&graph,int src,int dest,string path){
    if(src==dest){
        cout<<path + to_string(dest)<<endl;
        return;
    }
for(int i=0;i<graph[src].size();i++){
   int node =graph[src][i];
   printAllPaths(graph,node,dest,path+to_string(src));

}
}
int main(){
    int V=4;
    int src=0;
    int dest=3;
    vector<vector<int>>graph(V);
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(3);

    graph[2].push_back(3);
   

    cout<<"All Paths from"<<""<< src <<" "<<"to"<<dest<<endl;
    printAllPaths(graph,src,dest,"");

}