#include <bits/stdc++.h>
using namespace std;
class student{
    int roll no, marks;
    string name;
    public: 
    void getdata(){
        cin>>roll no>>marks;
        getline(cin,name);
    }
    void display(){
        cout<<roll no<<" "<<name;
    }
}
void swap(int a, int b){
    int temp=a;
    a=b;
    b=temp;
}

int main() {
  int  student a[10];
  for(int x=0; x<9; x++){
      a[x].getdata();}
      for(int i=0; i<9; i++){
          if(a[i].marks<a[i+1].marks){
              swap(a[i].marks,a[i+1].marks)
          }
          
      }
      return 0;
    
	

}
