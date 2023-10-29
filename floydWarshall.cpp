#include<iostream>
using namespace std;
#include<vector>
int main(){
//input.............................>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    //0 1 43
    //1 0 6
    //-1 -1 0
    //output.............................................>>>>>>>>>>>>>>>>>>>
    // 0 1 7
    // 1 0 6
    // -1 -1 0

    int n;
    cout<<"enter the size of matrix :"<<endl;
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n,0));
    cout<<"enter the values in matrix :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
      for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	            if(i==j){
	                matrix[i][j]=0;
	            }
	        }
	    }
          for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
        cout<<"shortest path between all vertex :"<<endl;
        for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	           
	        }
        }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }

    return 0;
}