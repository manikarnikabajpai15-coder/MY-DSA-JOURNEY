/*#include <bits/stdc++.h>
using namespace std;//
void printsum(int n){//
    if(n==0){return;}//
    int sum=0;//
    sum=sum+n;//
    printsum(n-1);//
    
    
}//
int main(){//
   int answer=printsum(10);//
   cout<<answer;//
    return 0;//
    
}*/
   #include <bits/stdc++.h>
using namespace std;
int printsum(int n){
    if(n==0){return 0;}
    int sum=0;
    sum=n+printsum(n-1);
    return sum;
    
    
}
int main(){
   int answer=printsum(10);
   cout<<answer;
    return 0;
    
} 



