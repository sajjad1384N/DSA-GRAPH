#include<iostream>
using namespace std;
#include<vector>
#include<queue>
bool dfs(int node,int col,vector<int>adj[],int color[]){
    color[node]=col;
    for(auto it:adj[node]){
        if(color[it]==-1){
           if (dfs(it,!col,adj,color)==false) return false;
        }
        else if(color[it]==col){
               return false;
        }
    }

    return true;
    
}
    bool bipartite(){
        int V;
    cout<<"Enter the number of vertices:"<<endl;
    cin>>V;
    int E;
    cout<<"enter the number of edge :"<<endl;
     cin>>E;
    vector<int>adj[V];
     int color[V];
     for(int i=0;i<E;i++){
        cout<<"enter two vertices"<<endl;
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
	    for(int i=0;i<V;i++){
	        color[i]=-1;
	    }
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(dfs(i,0,adj,color)==false){
	                return false;
	            }
                else{
                   return true;
                }
	        }
	    }
    }
int main(){
    
       if (bipartite()){
        cout<<" Graph is bipartite!"<<endl;
       }
       else{
        cout<<"Graph is not bipartite!"<<endl;
       }
        return 0;

}


	
