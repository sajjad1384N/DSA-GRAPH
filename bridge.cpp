#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<utility>
#include<queue>
#include<stack>

class Solution
{
public:
    int timer = 1;

    int dfs(int node, int parent, int c, int d, int time[], int low[], vector<int>& visit, vector<int> adj[])
    {
        visit[node] = 1;
        low[node] = time[node] = timer;
        timer++;
        int bridge = 0; // Add a variable to track whether this edge is a bridge

        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (visit[it] == 0)
            {
                dfs(it, node, c, d, time, low, visit, adj);
                low[node] = min(low[node], low[it]);

                // Check if this edge is a bridge
                if (low[it] > time[node] && ((node == c && it == d) || (node == d && it == c)))
                {
                    bridge = 1;
                }
            }
            else
            {
                low[node] = min(low[node], time[it]);
            }
        }
        return bridge; // Return whether this edge is a bridge
    }

    // Function to find if the given edge is a bridge in the graph.
    void isBridge(int V, vector<int> adj[], int c, int d)
    {
         int rootBridge=0;
        int time[V];
        int low[V];
        vector<int> visit(V, 0);
        int result = dfs(0, -1, c, d, time, low, visit, adj);
          if(c==0&&visit[c]==0){
            rootBridge=1;
          }
          if(result|| rootBridge){
            
          }
          
          
          
       
    }
};
int main(){
    Solution bridge;
       int V;
      
    //   int timer=1;
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
    int c,d;
    cout<<"enter value of c and d: "<<endl;
    cin>> c >> d;
    bridge.isBridge(V,adj,c,d);
    

}
