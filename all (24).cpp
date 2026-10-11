#include <bits/stdc++.h>
using namespace std;
void printnumber(int n){
    if(n==0){
        return ;
    }
    cout<<n<<endl;
    printnumber(n-1);
    
}


int main() {
    printnumber(8);
   return 0;
    


}
