#include<iostream> 
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data= val;
        next= NULL;

    }
};
class list{
    node*head;
    node*tail;  

    list(){
        head= NULL;
        tail = NULL;

    };
int find_index(node*tail, node*head){
    node*temp= head;
   int index=0;
    while(temp!=NULL){
        if(temp==tail){cout<<index;
            break;}
            temp= temp->next;
            index++;
    };
    return index;
}










    

};




int main(){






    return 0;
}