#include<iostream> 
#include<vector>
using namespace std;
/*
stack using vector
class stack{
    vector<int>vec;
    public:
   void push(int val){
        vec.push_back(val);

    }
    void pop(){
        if(isempty()){
            cout<<"stack is empty";
            return;
        }
        vec.pop_back();
        
    }
    int top(){
        if(isempty()){
            cout<<"stack is empty";
            return;

        }
        int lastidx= vec.size()-1;
        return  vec[lastidx];
    }
    bool isempty(){
        return vec.size()==0;
}}
        int main(){
    stack s;
    s.push(2);
    s.push(1);
    s.push(0);

    return 0;
}
*/
  // stack using class template
   template<class T>
class Stack{
    vector<T>vec;
    public:
   void push(T val){
        vec.push_back(val);

    }
    void pop(){
        if(isempty()){
            cout<<"stack is empty";
            return;
        }
        vec.pop_back();
        
    }
    T top(){
        if(isempty()){
            cout<<"stack is empty";
            return -1;

        }
        int lastidx= vec.size()-1;
        return  vec[lastidx];
    }
    bool isempty(){
        return vec.size()==0;
    }


};
int main(){
    Stack<char>s;
    s.push('a');
    s.push('b');
    s.push('c');
    while(!s.isempty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
