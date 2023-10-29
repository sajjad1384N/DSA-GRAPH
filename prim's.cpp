#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<utility>
#include<queue>
int main(){
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
}//in th priority queue smallest element always on the top of queue
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     vector<int>visit(V,0);
     int sum=0;
     pq.push({0,0});
       while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            //if node is visited then
               //it means that node is already in the mst so just return it
              if(visit[node]==1) continue;
              //node is not visited then mark as visited this is part of th mst add the sum of edge
                 visit[node]=1;
                  sum+=wt;
              //traverse the all adjacent nodes of node;
              for( auto it:adj[node]){
                  int adjNode=it[0];
                  int edgeWeight=it[1];
                  if(!visit[adjNode]){
                      pq.push({edgeWeight,adjNode});
                  }
                  
              }
         }
         cout<<"Sum of the minimum spanning tree edges is:"<<sum;
    return 0;
}