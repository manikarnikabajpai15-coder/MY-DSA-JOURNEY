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






        return 0;
    }*/
   #include<iostream>
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
            };

                
            




    
   };
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
    return 0;



   }
   