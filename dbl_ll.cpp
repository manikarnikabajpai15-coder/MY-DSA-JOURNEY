#include<iostream>
using namespace std;
class node{ public: 
    int data;
    node* prev;
    node* next;
    node(int val){
        data= val;
        prev= NULL;
        next= NULL;
    }

};
class doublylist{ public:

    node* head;
    node* tail;
    doublylist(){
        head= tail= NULL;
    }
    void push_front(int val){
        node* newnode= new node(val);
        

        if(head== NULL){
             head= tail= newnode;
            head->prev= NULL;
            tail->next= NULL;}
            else{
                head->prev= newnode;
                newnode->next=head;
                head= newnode;

            }


        
    }
    void print_list(){
        node*temp=head;
        if(head==NULL){
            cout<<"dll is empty";
        }
        else{
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }

        }
    }void push_back(int val){
        node* newnode= new node(val);
        if(head==NULL){
            head= tail= newnode;
        }
        else{
            tail->next= newnode;
            newnode->prev= tail;
            newnode->next= NULL;
            tail= newnode;
        }
    }

};

int main(){
doublylist dll;
dll.push_front(4);
dll.push_front(3);
dll.push_front(2);
dll.push_back(5);
dll.print_list();
    return 0;
}