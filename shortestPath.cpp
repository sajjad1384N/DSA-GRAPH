#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include <climits>

  void dfs(int node, vector<pair<int, int>> adj[], stack<int>& st, int visit[]) {
        visit[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!visit[v]) {
                dfs(v, adj, st, visit);
            }
        }
        st.push(node);
    }


int main(){
     int V;
    cout<<"Enter the value of V: "<<endl;
    cin>>V;
    vector<pair<int, int>> adj[V];
    int E;
    cout<<"Enter the number of edges: "<<endl;
    cin >> E;
    
    for(int i = 0; i <E; i++) {
        int u, v,wt;
        cout << "Enter the edge (u, {v,wt}): "<<endl;
        cin >> u >> v >>wt;
        
        adj[u].push_back({v,wt}); 
       
    }
     stack<int> st;
        int visit[V] = { 0 };
        for (int i = 0; i < V; i++) {
            if (!visit[i]) {
                dfs(i, adj, st, visit);
            }
        }
   
    vector<int> dist(V, INT_MAX); // Initialize all nodes to INT_MAX
        dist[0] = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] != INT_MAX && dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            cout<<dist[i]<<" ";
        }

}
    

