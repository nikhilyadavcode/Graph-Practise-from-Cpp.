#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool canFinish(int numCourses,vector<vector<int>>&prerequisites){
vector<vector<int>>adj(numCourses);
vector<int>indegree(numCourses,0);

for(auto &p:prerequisites){
    int course=p[0];
    int pre=p[1];
    adj[pre].push_back(course);
    indegree[course]++;
}
queue<int>q;
for(int i=0;i<numCourses;i++){
    if(indegree[i]==0) q.push(i);
}
int count=0;
while(!q.empty()){
    int node=q.front();
    q.pop();
    count++;

    for(int v:adj[node]){
        indegree[v]--;
        if(indegree[v]==0) q.push(v);
    }
}
return count==numCourses;
}
int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}}; 
    cout << (canFinish(numCourses, prerequisites) ? "true" : "false") << endl;

    numCourses = 2;
    prerequisites = {{1,0},{0,1}}; 
    cout << (canFinish(numCourses, prerequisites) ? "true" : "false") << endl;

    return 0;
}