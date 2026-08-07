#include <iostream>
using namespace std;
 int gridways(int r, int c, int n, int m, string ans){
     if(r==n-1 && c==m-1){
         cout<<ans<<" "<<endl;
         return 1;
     }
     if(r>=n || c>=m){
         return 0;
     }
     //way1
     int val1= gridways(r,c+1,n,m,ans+"R");
     //way2
     int val2= gridways(r+1, c,n,m,ans+"D");
     return val1+ val2;}
     
     int main(){
         int n=3;
          int m=3;
          string ans="";
         cout<<gridways(0,0,m,n,ans);
         return 0;
         
         
         
         
         
         
     
 }