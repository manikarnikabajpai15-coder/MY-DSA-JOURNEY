#include <bits/stdc++.h>
using namespace std;


void sum(int n, int i){
	    if(i<=10)
	    
	    {
	        cout<<n*i<<endl;
	       sum(n,i+1);
	        
	         
	    }
	}
	int main(){
	    int n ;
	    cin>>n;
	    sum(n,1);
	    
	    return 0;
	    
	}


