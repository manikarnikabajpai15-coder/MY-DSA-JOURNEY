#include <bits/stdc++.h>

using namespace std;

int main() {
    int a; int b; int c;
    cin>>a>>b>>c;
    int d= b*b - 4*a*c;
    if (d>0){cout<<"real roots";}
    else if(d<0){cout<<"imaginary roots";}
    else {cout<<"equal roots";}


return 0;
	// your code goes here

}
