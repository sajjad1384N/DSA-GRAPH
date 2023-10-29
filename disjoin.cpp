#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<utility>
#include<queue>
class DisjointSet{
    public:
     vector<int>parent,rank,size;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;        }
    }
        int findUPar(int node) {
            if(node==parent[node]){
                return node;
           
            }//path compression
                 return parent[node]=findUPar(parent[node]);
            
        }
        void findUnionByRank(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v) return ;
            if(rank[ulp_u]<rank[ulp_v]){
                //move ulp_u under ulp_v
                parent[ulp_u]=ulp_v;

            } 
            else if(rank[ulp_v]<rank[ulp_u]){
                //move ulp_v under ulp_u
                parent[ulp_v]=ulp_u;
            } 
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }              
            }
            void findUnionBySize(int u,int v){
                int ulp_u=findUPar(u);
                int ulp_v=findUPar(v);
                if(ulp_u==ulp_v)return;
                if(size[ulp_u]<size[ulp_v]){
                    parent[ulp_u]=ulp_v;
                    size[ulp_v]+=size[ulp_u];
                }
                else{
                    parent[ulp_v]=ulp_u;
                    size[ulp_u]+=size[ulp_v];
                }
            }
    
};
int main(){

    // 1.find ulternate parent;
    // 2 compare the  rank of ulp_u and ulp_v ;
    // 3.connect smaller rank to larger rank
cout<<"Disjoint By Rank : "<<endl;
    DisjointSet ds1(7);
    ds1.findUnionByRank(1,2);
    ds1.findUnionByRank(2,3);
    ds1.findUnionByRank(4,5);
    ds1.findUnionByRank(6,7);
    ds1.findUnionByRank(5,6);
    if(ds1.findUPar(3)==ds1.findUPar(7)){
        cout<<"same:"<<endl;
    }
    else{
        cout <<"Not Same:"<< endl;
    }
    ds1.findUnionByRank(3,7);
     if(ds1.findUPar(3)==ds1.findUPar(7)){
        cout<<"same:"<<endl;
    }else{
        cout<<"Not Same:"<<endl;
    }

cout<<"DisjointBySize:"<<endl;
 DisjointSet ds2(7);
    ds2.findUnionBySize(1,2);
    ds2.findUnionBySize(2,3);
    ds2.findUnionBySize(4,5);
    ds2.findUnionBySize(6,7);
    ds2.findUnionBySize(5,6);
    if(ds2.findUPar(3)==ds2.findUPar(7)){
        cout<<"same:"<<endl;
    }
    else{
        cout <<"Not Same:"<< endl;
    }
    ds2.findUnionBySize(3,7);
     if(ds2.findUPar(3)==ds2.findUPar(7)){
        cout<<"same:"<<endl;
    }else{
        cout<<"Not Same:"<<endl;
    }
    return 0;
}