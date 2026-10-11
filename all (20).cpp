#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; int digit; int sum=0;
	cin>>n;
	while(n>0){
	    digit=n%10;
	    sum= sum +digit;
	    n=n/10;
	    
	}
	cout<<sum;
	return 0;
	

}
