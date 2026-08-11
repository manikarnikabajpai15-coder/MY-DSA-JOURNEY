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
/*#include<iostream> 
#include<stack>
#include<string>       
using namespace std;
void print(stack<int>& s){
    while(!s.empty()){
    cout<<s.top();
    s.pop();
};
}
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
}*/
/*void rev_stack(stack<int>& s){
    if(s.empty()){
        return;
    }
int temp= s.top();
s.pop();
rev_stack(s);
push_at_btm(s,temp);
print(s);

}/*
int main()   {
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);
   /*push_at_btm(s,4);
    while(!s.empty()){
        cout<<s.top()<<" ";/
        s.pop();
    }*/
   /*stack<char>s;
   rev_string(s,"abcd");
   rev_stack(s);
   
    return 0;
    

    
    
}*/
/*#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void stock_span(vector<int> stock, vector<int> span){
    stack<int> s;
    s.push(0);
    span[0]=1;
    for(int i=1; i<stock.size(); i++){
        int currPrice= stock[i];
        while(!s.empty() && currPrice>=stock[s.top()]){
            s.pop();
        };
        if(s.empty()){
            span[i]= i+1;
        }
        else{
            int prevHigh= s.top();
            span[i]= i-prevHigh;
        };
    };
    for(int i=0; i<span.size(); i++){
        cout<<span[i]<<" ";
    };
};*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void next_greater(vector<int> arr, vector<int>& ans) {
    stack<int> s;

    // Right se left traverse karenge
    for (int i = arr.size() - 1; i >= 0; i--) {

        // Chhote/equal elements ko remove karo
        while (!s.empty() && arr[i] >= s.top()) {
            s.pop();
        }

        // Stack empty hai -> koi greater element nahi
        if (s.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = s.top();
        }

        // Current element ko stack mein push karo
        s.push(arr[i]);
    }
}

int main() {

    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int> ans(arr.size());

    next_greater(arr, ans);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
};
