/*
in unordered maps : the order not gets maintained
                     the time complexity is less average :o(1) worst: o(n)
                     the space complexity is more
ordered maps      : the order gets maintained
                     the time complexity is more average o(logn)
                     the space complexity is less*/
#include<iostream>
#include<unordered_map>
using namespace std; 
int main(){
    /*unordered_map<string,int> m;
    m["china"]= 300;
    m["india"]=150;
    m["uk"]=200;
    for(pair<string,int>country:m){
        cout<<country.first<<"->"<<country.second<<endl;
    }
    if(m.count("china")==1){cout<<"china exists";}
    else{
        cout<<"china dont exists";
    }*/
   int a[7]={1,2,7,11,15,5,9};
   int n=7;
   int target=9;
   unordered_map<int,int>m;
   for(int i=0; i<n; i++){
    int comp=target-a[i];
    if(m.count(comp)){
        cout<<m[comp]<<" "<<i<<endl;
        break;

    }
    m[a[i]]=i;

   }
   return 0;

   

    

}
