
#include <bits/stdc++.h>
using namespace std;
vector<int> bfsTrav(vector<vector<int>> &adjList, int v){
    vector<bool> vis(v,false);
    vector<int> result;
    queue<int> q;
    q.push(0);
    vis[0]=true;
    while(!q.empty()){
        int node = q.front();
        result.push_back(node);
        q.pop();
        for(auto it: adjList[node]){
            if(!vis[it]){
                vis[it]=true;
                q.push(it);
            }
        }
    }
    return result;
}
int main() {
    int v,e;
    cout<<"Enter number of vertices"<<endl;
    cin>>v;
    cout<<"Enter number of edges"<<endl;
    cin>>e;
    vector<vector<int>> adjList(v);
    cout<<"Enter "<<e<<" edges (u, v format)\n";
    for(int i=0; i<e; i++){
        int u, vertex;
        cin>>u>>vertex;
        adjList[u].push_back(vertex);
        adjList[vertex].push_back(u);
    }
    vector<int> result = bfsTrav(adjList,v);
    for(auto it: result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// Enter number of vertices
// 5
// Enter number of edges
// 5
// Enter 5 edges (u, v format)
// 0 1
// 0 2
// 1 2
// 2 3
// 2 4

// Output:
// 0 1 2 3 4 