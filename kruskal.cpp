#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<utility>
#include<queue>
#include<algorithm>
class DisjointSet{
    public:
     vector<int>parent,rank;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
    
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
                    
    }
    }
        int findUPar(int node) {
            if(node==parent[node]){
                return node;
           
            }//path compression
                 return parent[node]=findUPar(parent[node]);
            
        }
        void findUnionByRank(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v) return ;
            if(rank[ulp_u]<rank[ulp_v]){
                //move ulp_u under ulp_v
                parent[ulp_u]=ulp_v;

            } 
            else if(rank[ulp_v]<rank[ulp_u]){
                //move ulp_v under ulp_u
                parent[ulp_v]=ulp_u;
            } 
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }              
            }
};
int main(){
      int V;
       int edgeWeight=0;
    cout<<"Enter the value of V: "<<endl;
    cin>>V;
    vector<vector<int>> adj[V];
    int E;
    cout<<"Enter the number of edges: "<<endl;
    cin>>E;
       for (int i = 0; i < E; i++) {
    int u, v,wt;
    cout << "Enter the edge (u,v): " << endl;
    cin >> u >> v >> wt;// With spaces for better readability between two input u and  v values lik u v
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});

       }
       vector<pair<int,pair<int,int>>> edges;
       for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            int adjNode=it[0];
            int wt=it[1];
            int node=i;
            edges.push_back({wt,{node,adjNode}});
        }
        //sort the edges for weights of
       
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUPar(u)!=ds.findUPar(v)){
                edgeWeight+=wt;
                ds.findUnionByRank(u,v);
            }
        }
       }
       cout<<" sum of the minimum spanning tree:"<<edgeWeight;

   return 0;
}