
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
int main(){
    int V;
    cout<<"enter the value of V"<<endl;
    cin>>V;
    vector<int>adj[V];
    stack<int>st;
    int visit[V]={0};
    for(int i=0;i<V;i++){
        int u,v;
        cout<<"enter the vertex(u,v)"<<endl;
        cin>>u>>v;
    }
    for(int i=0;i<V;i++){
        if(!visit[i]){
            dfs(i,st,visit,adj);
        }
    }