#include<iostream>
#include<utility>
using namespace std;
#include<vector>
#include<queue>
int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        //({r,c},t}
        queue<pair<pair<int,int>,int>>q;
        int visit [n][m];
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visit[i][j]=2;
            }
            else{
                visit[i][j]=0;
            }
        }
        }
        int ct=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
             ct=max(ct,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n &&ncol>=0&& ncol<m &&grid[nrow][ncol]&& grid[nrow][ncol]==1&& visit[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    visit[nrow][ncol]=2;
                }
                
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&& visit[i][j]!=2){
                    return -1;
                }
            }
        }
        return ct;
    }
int main(){
    int row,col;
    cout<<"enter row number"<<endl;
    cin>>row;
    cout<<"enter col number"<<endl;
    cin>>col;
    vector<vector<int>>grid(row,vector<int>(col));
    cout<<"enter value in the grid"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>grid[i][j];
        }
    }
    int totalTime=orangesRotting(grid);
    if(totalTime>0){
        cout <<"total time taken to rotten all oranges :"<<totalTime<<endl;

    }
    else{
        cout<<"all oranges are not rotten :"<<-1;
    }
    

}