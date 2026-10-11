
   #include <bits/stdc++.h>
using namespace std;
class student{
    public:
    int roll_no, marks;
    string name;
    void getdata(){
        cin>>roll_no>>marks;
        cin.ignore(); 
        getline(cin,name);
    }
    void display(){
        cout<<roll_no<<marks<<name<<endl;
    }
};
void swapmarks(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

int main() {
  student a[10];
  for(int x=0; x<10; x++){
      a[x].getdata();}
      for(int i=0; i<9; i++){
          if(a[i].marks<a[i+1].marks){
              swapmarks(a[i].marks,a[i+1].marks);
          }
          
      }
      a[9].display();
      
      return 0;
    
}

