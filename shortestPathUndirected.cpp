#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include <climits>
int main(){
     int V;
    cout<<"Enter the value of V: "<<endl;
    cin>>V;
    vector<int> adj[V];
    int E;
    cout<<"Enter the number of edges: "<<endl;
    cin >> E;
    
    for (int i = 0; i < E; i++) {
    int u, v;
    //wee can take edges between u and v[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]]
    cout << "Enter the edge (u,v): " << endl;
    cin >> u >> v;// With spaces for better readability between two input u and  v values lik u v
    adj[u].push_back(v);
    adj[v].push_back(u);
}

    int src;
    cout<<"Enter the edge(src): "<<endl;
    cin>>src;
     vector<int>dist(V,1e9);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();

            //weight between two node are considered as 1
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        vector<int>ans(V,-1);
        for(int i=0;i<V;i++){
            if(dist[i]!=1e9){
                ans[i]=dist[i];
            }
        }
        for(int i=0;i<V;i++){
            cout<<ans[i]<<" ";
        }
}