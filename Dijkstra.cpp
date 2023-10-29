#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include <climits>
#include<queue>
int main(){
    //input:
//     V = 3, E = 3
// adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
// S = 2
// Output:
// 4 3 0
//time complexity:O(ElogV)

     int V;
    cout<<"Enter the value of V: "<<endl;
    cin>>V;
    vector<vector<int>> adj[V];
    int E;
    cout<<"Enter the number of edges: "<<endl;
    cin >> E;
    
    for (int i = 0; i < E; i++) {
    int u, v,wt;
    cout << "Enter the edge (u,v): " << endl;
    cin >> u >> v >> wt;// With spaces for better readability between two input u and  v values lik u v
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}
int src;
cout<<"enter the source direction"<<endl;
cin>>src;
vector<int>dist(V,1e9);
dist[src]=0;
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
 pq.push({0,src});
  while(!pq.empty()){//O(V)
            int dis=pq.top().first;//Olog(heap size)
            int node=pq.top().second;//
            pq.pop();
            for(auto it:adj[node]){// O(V-1)
                int edgeWeight=it[1];
                int adjNode=it[0];
                if(dis+edgeWeight<dist[adjNode]){
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});//Olog(heap size)
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
    
// O(V*(pop vertex from min heap+ no of edges on each vertex *push into pq))
//O(V*(log(heap size)+ne+log(heap size)))
//O(V*(log(heap size)*(ne+1)))
//O(V*(log(heap size)*(V-1+1)))
//O(V*(log(heap size)*V))
//O(V^2*(log(heap size)))
//O(V^2(log(v^2)))
//O(V^2*2(log(V)))
//O(E(log(V)))
}