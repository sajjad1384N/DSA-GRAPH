#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include <climits>
#include<list>
int main(){
     int V;
    cout<<"Enter the value of V: "<<endl;
    cin>>V;
    vector<vector<int>>edges;
    int E;
    cout<<"Enter the number of edges: "<<endl;
    cin >> E;
    vector<int>result;
    for (int i = 0; i < E; i++) {
    int u, v,wt;
    cout << "Enter the edge (u,v): " << endl;
    cin >> u >> v >> wt;// With spaces for better readability between two input u and  v values lik u v
   result.push_back(u);
   result.push_back(v);
   result.push_back(wt);
   edges.push_back(result);
   
}

    int src;
    cout<<"Enter the edge(src): "<<endl;
    cin>>src;
     vector<int>dist(V,1e9);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
              for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e9 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
            
        }
        //nth relaxation to check negative cycle
        for(int i=0;i<V-1;i++){
             for(auto it:edges){
             int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e8&& dist[u]+wt<dist[v]){
            return {-1};
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