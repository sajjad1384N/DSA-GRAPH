#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<utility>
#include<queue>
#include<stack>
    // 1->0
    // 0->2
    // 2->1
    // 0->3
    // 3->4
	void dfs(int node,vector<int>&visit,vector<int>adj[],stack<int>&st){
	    visit[node]=1;
	    for(auto it:adj[node]){
	        if(!visit[it]){
	            dfs(it,visit,adj,st);
	        }
	    }
	    st.push(node);
	}
    	void dfs2(int node,vector<int>&visit,vector<int>reverseAdj[]){
	     visit[node]=1;
	     for(auto it:reverseAdj[node]){
	         if(!visit[it]){
	             dfs2(it,visit,reverseAdj);
	         }
	     }
	}
int main(){
    //to find the number of strongly connected components
    //1. sort the nodes(dsf)
    //2.reverse the node of original on adjacent list
    //3.perform dfs on the stack element(declare the new adjacent the list)
      int V;
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
   
    }
      vector<int>visit(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visit[i]){
                dfs(i,visit,adj,st);
            }
        }
          //this store the reverse node
        vector<int>reverseAdj[V];
        for(int i=0;i<V;i++){
            visit[i]=0;
            for(auto it:adj[i]){
                // it is the adjcent  of i
                //i->it
                //reverse it
                //it->i
                // i is the adjacent of it
                reverseAdj[it].push_back(i);
            }
        }
          int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visit[node]){
                scc++;
                dfs2(node,visit,reverseAdj);
            }
            
        }
        cout<<" number of strongly connected components :"<<scc;
    return 0;
}