#include<iostream>
#include <algorithm>
using namespace std;
 
int n;
 
int arr[510][510];
int d[510][510];
 
int dy[4]= {0,0,1,-1};
int dx[4]= {1,-1,0,0};
 
int go ( int ypos , int xpos){
    if (d[ypos][xpos]==1){
        for (int i =0 ;i<4;i++){
            int ny = dy[i]+ypos;
            int nx = dx[i]+xpos;
             
            if ( ny < 0 || nx<0 || ny>=n || nx>=n ) continue;
            if ( arr[ypos][xpos] <= arr[ny][nx] ) continue;
             
            d[ypos][xpos]= max ( d[ypos][xpos], go(ny,nx)+1 );
             
        }
    }
     
    return d[ypos][xpos];
    
}

int main ()
{
    cin>>n;
    
    for (int i =0 ;i<n;i++){ 
        for (int j=0; j<n;j++){ 
            cin>>arr[i][j];
            d[i][j]=1;
        }
    }
 
    int ans=-1;
    for (int i =0 ;i<n;i++){
        for (int j= 0 ;j<n;j++){
            ans= max( go(i,j),ans ) ;
        }
    }
 
    cout<<ans<<endl;
     
}