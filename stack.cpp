/*/*#include<iostream> 
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
#include<iostream>
#include<stack>
using namespace std;
int main(){
    Stack<int>s;
    s.push(2);
    cout<<s.top();
    return 0;
};  */        
#include<iostream> 
#include<stack>
#include<string>       
using namespace std;
void push_at_btm(stack<int>& s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp= s.top();
    s.pop();
    push_at_btm(s,val);
    s.push(temp);
}  
void rev_string(stack<char>& s, string r){
for(int i=0; i<r.length(); i++){
    s.push(r[i]);
};
while(!s.empty()){
    cout<<s.top();
    s.pop();
};
}
int main()   {
    /*stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);
    push_at_btm(s,4);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }*/
   stack<char>s;
   rev_string(s,"abcd");
    return 0;
    

    
    
}
