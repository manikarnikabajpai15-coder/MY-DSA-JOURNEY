#include <bits/stdc++.h>
using namespace std;


int sum(int n, int i){
	    if(i>10)
	    return 0;
	    else{
	        cout<<n*i<<endl;
	      return  sum(n,i+1);
	        
	         
	    }
	}
	int main(){
	    int n, f;
	    cin>>n;
	    f=sum(n,1);
	    cout<<f;cout<<endl;
	    return 0;
	    
	}


