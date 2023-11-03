#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<utility>
#include<queue>
#include<stack>
 void dfs(int node,int visit[],vector<int>adjList[]){
      visit[node]=1;
      for(auto it:adjList[node]){
          if(!visit[it]){
              dfs(it,visit,adjList);
          }
      }
  }
int main(){
    int V;
    cout<<"Enter the number of vertices :"<<endl;
    cin>>V;
    vector<vector<int>>adjMatrix(V,vector<int>(V,0));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>> adjMatrix[i][j];
        }
    }
    vector<int>adjList[V];
    for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
        if(adjMatrix[i][j]==1 && i!=j){
            adjList[i].push_back(j);
            adjList[j].push_back(i);       
             }
    }
    }
    int count=0;
    int visit[V]={0};
     for(int i=0;i<V;i++){
            if(!visit[i]){
                count++;
                dfs(i,visit,adjList);
            }
        }
        cout<<"total number of princess:"<<count;
    
}