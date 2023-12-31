#include<iostream>
using namespace std;
#include<vector>
#include<queue>
bool check(int start,int V,vector<int>adj[],int color[]){
    color[start]=0;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node]){
                return false;
            }
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
	            if(check(i,V,adj,color)==false){
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


	
