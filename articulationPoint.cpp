#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<utility>
#include<queue>
#include<stack>
    vector<int> dfs(int node,int parent,int low[],int time[],vector<int>&visit,vector<int>&mark,vector<int>adj[],int timer){
        int child=0;
        visit[node]=1;
        low[node]=time[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(!visit[it]){
                dfs(it,node,low,time,visit,mark,adj,timer);
                low[node]=min(low[node],low[it]);
                if(low[it]>=time[node]&& parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],time[it]);
            }
        }
            if(child>1 && parent==-1){
                mark[node]=1;
            }
    return mark;
    }
int main(){
    // articulation point ->node on whose removal graph breaks into more components
    // 1.int time[]-> store the time of insertion on during dfs
    // 2.int  low[]->min of all adjacent node apart from parent and visited node

     int V;
       int timer=0;
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

     vector<int>visit(V,0);
        int time[V];
        int low[V];
        vector<int>mark(V,0);
        for(int i=0;i<V;i++){
            if(!visit[i]){
                dfs(i,-1,low,time,visit,mark,adj,timer);
            }
        }
            vector<int>ans;
            for(int i=0;i<V;i++){
                if(mark[i]==1){
                    ans.push_back(i);
                }
            }
            cout<<"articulation points: ";
            if(ans.size()==0){
                cout<<"-1";
            }
            else{
                for(int i=0;i<ans.size();i++){
                   cout<<ans[i]<<" ";
            }
            }
            // for(int i=0;i<mark.size();i++){
            //     cout<<mark[i]<<" " ;
            // }
            
    return 0;
}