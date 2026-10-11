
#include <bits/stdc++.h>
#include<string>
using namespace std;

int main() {
    int n; int k; string res="";
    cin>>n>>k;
    string s;
    cin.ignore();
    getline(cin,s);
    for(int x=0; x<n; x=x+3){
    
   if(x%2==0) {string p= s.substr(x,k);
    res= res+p;}
   else{ string q= s.substr(x, k);
 reverse(q.begin(), q.end());
 res=res+q;}}
 cout<<res;
 
    
    return 0;}




