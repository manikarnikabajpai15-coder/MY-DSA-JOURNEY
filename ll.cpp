	#include <bits/stdc++.h>
using namespace std;
class node{ public:
    int data;
    node* next;
    
    node(int val){
        data= val;
        next = NULL;
    };
};
class List{ public:
    node* head;
    node* tail;
    
    List(){
        head = NULL;
        tail= NULL;
    }
    void push_front(int val){
        node*newnode= new node(val);
        if(head==NULL){
            head = tail=  newnode;
        }
        else{
            newnode->next=head;
            head = newnode;
        }
        
    }
    void push_back(int val){
        node* newnode= new node(val);
        if(head==NULL){
            head =tail = newnode;
        }
        else{
            tail->next= newnode;
            tail= newnode;
        }
    }
    void print_list(node*head){
        node*temp= head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    void pop_front(){
        if(head==NULL){
            cout<<"linked list is empty";
        }
       else{ node*temp= head;
        head= head->next;
        delete temp;
    };
};
    void pop_back(){
        if(head==NULL){
            cout<<"list is empty";
        }
        else{
            node*temp= head;
            while(temp->next->next!=NULL){
                temp= temp->next;
            }
            temp->next= NULL;
            delete tail;
            tail= temp;
        }
    }
    int searchitr(int key){
        node*temp= head;
        int idx= 0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;}
                temp= temp->next;
                idx++;
            
            
        }
        return -1;
    }
    int helper(node*temp, int key){
        if(temp==NULL){
            return -1;
        }
        if(temp->data==key){
            return 0;
        }
        int idx= helper(temp->next, key);
        if(idx==-1){
            return -1;
        }
        return idx+1;
    }
    int searchkey(int key){
       return helper(head,key);}
       void reverse(){
        node* current = head;
        node*prev = NULL;
        while(current!= NULL){
            node* next= current->next;
            current->next = prev;
            prev= current;
            current = next;
        }
        head =prev;
       }
       int getsize(){
        int sz=0;
        node*temp= head;
        while(temp->next!=NULL){
            temp= temp->next;
            sz++;
        }
    return sz;}
        
    
       void remove_nth(int n){
        int size= getsize();
        node*prev= head;
        for(int i=1; i<(size-n); i++){
            prev= prev->next;
        }
        prev->next= prev->next->next;

       }
     void detect_cycle(){
        node*slow = head;
        node*fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
            if(fast==slow){
                cout<<endl<<"linked list have cycle";
                break;
            }
            
            
        };
        
     }
     void remove_cycle(){
node* slow = head;
node* fast = head;
bool iscycle= false;
while(fast!= NULL && fast->next!= NULL){
    slow = slow->next;
    fast= fast->next->next;
    if(slow==fast){
        iscycle= true;
        break;};}
        if(!iscycle){
            return;
        }
    slow= head;
 if(slow==fast){
    while(fast->next!=slow){
        fast= fast->next;
    }
    fast->next= NULL;
 }
 else{
    node*prev= fast;
    while(slow!=fast){
        slow= slow->next;
        prev= fast;
        fast= fast->next;
    }
    prev->next= NULL;
 }

};
node* splitatmid(node*head){
    node*slow= head;
    node*fast= head;
    node*prev =NULL;
    while(fast!=NULL &&fast->next!=NULL){
        prev= slow;
        slow= slow->next;
        fast =fast->next->next;

    }
    if(prev!=NULL){
        prev->next= NULL;
    }
    return slow;
}
 node* merge(node*left, node*right){
    List ans;
    node*i= left;
    node*j= right;
    
    while(i!= NULL && j!= NULL ){
if(i->data<=j->data){
    ans.push_back(i->data);
    i=i->next;
}
else{
    ans.push_back(j->data);
    j=j->next;
}}
while(i!=NULL){
    ans.push_back(i->data);
i=i->next;}
    while(j!=NULL){
        ans.push_back(j->data);
        j= j->next;
    }
    return ans.head;

    
}
node* mergesort(node*head){
    if(head==NULL || head->next== NULL){
        return head;
    }
    node*righthead= splitatmid(head);
    node*left=mergesort(head);
    node*right=mergesort(righthead);
    return  merge(left,right);}
    node* reverse(node*head){
        node* prev = NULL;
        node* curr = head;
        node* next= NULL;
        while(curr!=NULL){
            next= curr->next;
            curr->next= prev;
            prev= curr;
            curr= next;
            

        }return prev;}


    
    node* zigzagll(node*head){
        node* righthead= splitatmid(head);
        node* reverserighthead= reverse(righthead);
        
        node*left = head;
        node*right= reverserighthead;
        node*tail= right;
        while(left!= NULL && right!= NULL){
            node*nextleft= left->next;
            node*nextright= right->next;
            left->next= right;
            right->next= nextleft;
            tail= right;
            left= nextleft;
            right= nextright;

        };
        if(right!=NULL){
            tail->next= right;
        }
        return head;

        

    }
    int find_index(node*, node*head){
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
    List ll1, ll2;
    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(3);
    ll1.push_back(6);
    ll1.push_back(7);
    ll2.push_back(4);
    ll2.push_back(5);
    ll2.push_back(6);
    find_index()

    

    





   return 0; }
        