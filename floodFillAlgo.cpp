#include<iostream>
using namespace std;
#include<vector>
    void dfs(int row,int col,int delrow[],int delcol[],int iniColor,int newColor,vector<vector<int>>&image,vector<vector<int>>&ans){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0&& nrow<n && ncol>=0&& ncol<m &&image[nrow][ncol]==iniColor&& ans[nrow][ncol]!=newColor){
                dfs(nrow,ncol,delrow,delcol,iniColor,newColor,image,ans);
            }
        }
    }
int main(){
    int V;
    cout<<"enter the size of matrix :"<<endl;
    cin>>V;
    vector<vector<int>>image(V,vector<int>(V,0));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin >> image[i][j];
        }
    }
    vector<vector<int>>ans=image;
    int sr,sc;
    cout<<"enter the source row :"<<endl;
    cin>>sr;
    cout<<"enter the source column :"<<endl;
    cin>>sc;
    int newColor;
    cout<<"enter the new color :"<<endl;
    cin>>newColor;

      int iniColor=image[sr][sc];
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(sr,sc,delrow,delcol,iniColor,newColor,image,ans);
    
    cout<<" Otput :"<<endl;
     for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<< ans[i][j]<<" " ;
        }
        cout<<endl;
    }
    
}