#include<iostream>
#include<vector>
using namespace std;
  bool dfsCheck(int node,vector<int>adj[],int visit[],int pathVis[]){
      visit[node]=1;
      pathVis[node]=1;
      for(auto  it: adj[node]){
          if(!visit[it]){
              
              //when the node is  not visited
              if(dfsCheck(it,adj,visit,pathVis)==true)
              return true;
          }//when adjacent node is visited and path is also visited
          else if(pathVis[it])
             return true;
      }
      pathVis[node]=0;
      return false;
      
  }
  bool isCycle(vector<int>adj[],int V)
  {
    int visit[V]={0};
    int pathVis[V]={0};
    for(int i=0;i<V;i++){
        if(!visit[i]){
            if(dfsCheck(i,adj,visit,pathVis)){
                return true;//If a cycle is found, return true
        }
    }
       
  }
  return false; //If no cycle is found in the entire graph, return false
  }
int main()
{
 int V;
 cout<<"Enter the  value of V"<<endl;
 cin>>V;
 vector<int>adj[V];
 int visit[V]={0};
 int pathVis[V]={0};
     for(int i=0;i<V;i++){
        int u,v;
        cout<<"enter the two vertex (u,v)"<<endl;
        cin>>u>>v;
        adj[u].push_back(v);
     }
     if(isCycle(adj,V)){
        cout<<"cycle detected"<<endl;
     }
     else{
        cout<<"no cycle detected"<<endl;
     }
        
 return 0;
}


