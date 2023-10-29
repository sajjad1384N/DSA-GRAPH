#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // space complexity of storing a graph using adajacent  list O(E)
        // E is the edge between two node
        // push back in the index of adj[u]
        adj[u].push_back(v);
        //push back in the index of adj[v]
        adj[v].push_back(u);
    }


}