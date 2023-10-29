#include<iostream>
using namespace std;
#include<vector>
#include<queue>

int main(){
    int V;
    cout<<"Enter the value of V: "<<endl;
    cin>>V;
    vector<int> adj[V];
    int indegree[V] = {0};
    
    int E;
    cout<<"Enter the number of edges: "<<endl;
    cin >> E;
    
    for(int i = 0; i <E; i++) {
        int u, v;
        cout << "Enter the edge (u, v): "<<endl;
        cin >> u >> v;
        
        adj[u].push_back(v); // Add v to the adjacency list of u
       // indegree[v]++; // Update the indegree of v
    }
    
    for(int i = 0; i <V; i++){
        cout << i << "->";
        for(auto &x : adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
     
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topSort;
    while(!q.empty()){
       int node=q.front();
       topSort.push_back(node);
       q.pop();
       //node is in your toposort 
       //so please remove it from indegree
       for( auto it:adj[node]){
           indegree[it]--;
           if(indegree[it]==0){
            q.push(it);
           }
       }
    }
    for(int i=0;i<topSort.size();i++){
        cout<<topSort[i]<<" ";
    }
    //prerequisites task
    //if cycle present in the directed graph then not possible to complete task 
     if(topSort.size()==V){
	        return true;// return cycle is not  present in the graph
	    }
	    else{
	        return false;//return if cycle is  present in  the graph
	    }
    return 0;
}

   
