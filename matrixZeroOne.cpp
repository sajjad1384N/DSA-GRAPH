
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include <climits>
#include<queue>
int main(){
    int n,m;
    cout<<"enter the number of row :"<<endl;
    cin>>n;
    cout<<"enter the number of column :"<<endl;
    cin>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    
	    vector<vector<int>>visit(n,vector<int>(m,0));
	    vector<vector<int>>dist(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                visit[i][j]=1;
	            }
	            else{
	                visit[i][j]=0;
	            }
	        }
	    }
	    int delrow[]={-1,0,+1,0};
	    int delcol[]={0,+1,0,-1};
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int steps=q.front().second;
	        q.pop();
	        dist[row][col]=steps;
	        for(int i=0;i<4;i++){
	            int nrow=row+delrow[i];
	            int ncol=col+delcol[i];
	            if(nrow>=0 && nrow<n && ncol>=0&& ncol<m &&visit[nrow][ncol]==0){
	                visit[nrow][ncol]=1;
	                q.push({{nrow,ncol},steps+1});
	            }
	        }
	    }
        cout<<"output:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dist[i][j]<<" ";

            }
            cout<<endl;
        }
}