#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<utility>
#include<queue>
#include<stack>

void dfs(int node,int parent,int low[],int time[],vector<int>&visit,vector<int>adj[],vector<vector<int>>&bridge, int timer){
    visit[node]=1;
    low[node]=time[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent) continue;
        if(visit[it]==0){
            dfs( it,node,low,time,visit,adj,bridge,timer);

            low[node]=min(low[node],low[it]);
            //condition for bridge
            if(low[it]>time[node]){
                bridge.push_back({it,node});
            }
        }
        else{

        low[node]=min(low[node],low[it]);
        }
    }
}
int main(){
    // if we remove edge between two nodes then it form 
    // two more component then we can say bridge between two node 
      int V;
      int timer=1;
    cout<<"Enter the value of V: "<<endl;
    cin>>V;
    vector<int> adj[V];
    int E;
    cout<<"Enter the number of edges: "<<endl;
    cin >> E;
    for (int i = 0; i < E; i++) {
    int u, v;
    cout << "Enter the edge (u,v): " << endl;
    cin >> u >> v ;// With spaces for better readability between two input u and  v values lik u v
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    vector<int>visit(V,0);
        int low[V];
        int time[V];
        vector<vector<int>>bridge;
        dfs(0,-1,low,time,visit,adj,bridge,timer);

     return 0;
}