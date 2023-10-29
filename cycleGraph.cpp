#include<iostream>
using namespace std;
#include<utility>
#include<queue>
#include<vector>
#include<queue>
//print adjList 
void printAdjList(int V,vector<int>adj[]){
      //print the value of adjacent lis
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(auto &x:adj[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }

}
//detect the cyclic graph in undirected graph using bsf
 bool detect(int src,int visit[],vector<int>adj[]){
      visit[src]=1;
      queue<pair<int,int>>q;
      q.push({src,-1});
      while(!q.empty()){
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
          for(auto adjacent: adj[node]){
              if(!visit[adjacent]){
                  visit[adjacent]=1;
                  q.push({adjacent,node});
              }
              else if(parent!=adjacent){
                  return true;
              }
              }
          }
          return false;
      }
int main(){
      //code here
      int V;
    cout<<"enter number of vertex"<<endl;
    cin>>V;
    vector<int>adj[V];
    for(int i=0;i<V;i++){
        cout<<"enter two vertex"<<endl;
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    printAdjList(V,adj);
      
        int visit[V]={0};
        for(int i=0;i<V;i++){
            if(!visit[i]){
                if(detect(i,visit,adj)==1){
                    cout<<"cycle is present in the graph"<<endl;
                }
                else {
                    cout<<"cycle is not present in the graph"<<endl;
                }
            }
        }
      
        

}