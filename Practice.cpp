#include<iostream>
using namespace std;
void print_num(int n, int p){
    cout<<n;
    if(n==p){
        return;
    }
    print_num(n+1,p);
    
    
}
void print(int n){
    cout<<n;
    if(n==1){
        return;
    }
    print(n-1);
}
int p(int n){
    int sum=0;
    if(n==0){
        return 0;
    }
    sum=n+p(n-1);
return sum;
}
int f(int n){
    int p=1;
    if(n==1){
        return 1;
    }
    p=n*f(n-1);
    return p;

}
void fibbo(int n,int a,int b){
    if(n==0){
        return ;
    }
    cout<<a<<" ";
 fibbo(n-1,b,a+b);
}
void dec_to_bin(int n){
    if(n==0){
        return;
    }
    dec_to_bin(n/2);
    cout<<n%2;

}
int main(){
    print_num(1,10);
    cout<<endl;
    print(10);
    cout<<endl;
    cout<<f(10)<<endl;
    cout<<p(10)<<endl;
    fibbo(10,0,1);
    cout<<endl;
    dec_to_bin(10);






return 0;}