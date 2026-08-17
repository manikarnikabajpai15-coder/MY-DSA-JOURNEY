//queue using ll
/*#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data= data;
        this->next=NULL;

    };

};
class queue{
    public:
    node* head;
    node* tail;
    queue(){
        head=tail=NULL;
    };
    void push(int data){
        node* newnode= new node(data);
        if(head==NULL){
            head=tail=newnode;

        }
        else{
        tail->next= newnode;
        tail=newnode;
                
            }
        };
        void pop(){
            if(head==NULL){
                cout<<"queue is empty";
            }
            else{
            node* temp = head;
            head=head->next;
            delete temp;
            };
        };
        int front(){
            return head->data;
        };
        bool is_empty(){
            if(head==NULL){
                return true;
            }
            return false;
        };
        
    };
    int main(){
        queue q;
        q.push(1);
        q.push(2);
        q.push(3);
        while(!q.is_empty()){
            cout<<q.front();
            q.pop();
        }
 return 0;}*/
   //circular queue using array
   /* #include<iostream>
   using namespace std;
   class queue{
    int *arr;
    int capacity;
    int currSize;
    int f,r;
    public:
    queue(int capacity){
        this->capacity= capacity;
        arr= new int[capacity];
        currSize=0;
        f=0;
    r=-1;}
        void push(int data){
            if(currSize==capacity){
                cout<<"queue is full\n";
                return;
            };
            r= (r+1)%capacity;
            arr[r]= data;
        currSize++;
    };
            void pop(){
                if(is_empty()){cout<<"queue is empty\n";
                return;}
                f= (f+1)%capacity;
                currSize--;
            };
            int front(){
                return arr[f];
            };
            bool is_empty(){
                if(currSize==0){
                    return true;
                };
                return false;
            };};
   int main(){
    queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.is_empty()){
        cout<<q.front();
        q.pop();
    };
    return 0;}*/
    //queue using stl
   /* #include<iostream>
    #include<queue>
    using namespace std;
    int main(){
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        while(!q.empty()){
            cout<<q.front()<<endl;
            q.pop();

        };
        return 0;
    }*/
   // queue using two stacks
   /*#include<iostream>
   #include<stack>
   using namespace std;
   class queue{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int data){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            };
            s1.push(data);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            };

    };
    void pop(){
        s1.pop();

    };
    int front(){
        return s1.top();

    };
    bool empty(){
        if(s1.empty()){
            return true;
        };
        return false;
    }

   };
   int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();

    };


    return 0;
   }*/
  //stack using two queues
  /*#include<iostream>
  #include<queue>
  using namespace std;
  class stack{
    queue<int> q1;
    queue<int> q2;
    public:
    void push(int data){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        };
    };
    void pop(){
        q1.pop();
    };
    int top(){
        return q1.front();
    };
    bool empty(){
        if(q1.empty()){
            return true;
        };
        return false;
    };


  };
  int main(){
    stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    };


    return 0;
  }*/
 //interleave 2 queues
 /*#include<iostream>
 #include<queue>
 using namespace std;

 int main(){
    queue<int> q1;
    for(int i=0; i<10; i++){
        q1.push(i);
    };
    queue<int> q2;
    for(int i=0; i<5; i++){
        q2.push(i);
        q1.pop();
    };
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
        q1.push(q1.front());
        q1.pop();
    };
    while(!q1.empty()){
        cout<<q1.front();
        q1.pop();
    };

    return 0;
 }*/
//queue reversal
/*#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
    stack<int> s;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    };
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    };
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    };

    return 0;
}*/
//deque->double ended queue
/*#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> d;
    d.push_back(1);
    d.pop_front(2);
    d.push_front(3);
    d.pop_back(4);
    d.front();
    d.back();
    return 0;

}*/
//queue using deque
#include<iostream>
#include<deque>
using namespace std;
class queue{
    deque<int> d;
    public:
    void push(int data){
        d.push_back(data);

    };
    void pop(){
        d.pop_front();
    };
    int front(){
        return d.front();
    };
    bool empty(){
        if(d.empty()){
            return true;
        };
        return false;
    };
};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    };

    return 0;
}

   