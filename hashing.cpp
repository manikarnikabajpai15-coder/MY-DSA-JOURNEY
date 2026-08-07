#include<iostream>
#include<vector>
#include<string>
using namespace std;
class node{
    public:
    string key;
    int val;
    node*next;
    node(string key, int val){
        this->key=key;
        this->val=val;
        next=NULL;

    }
    ~node(){
        if(next!=NULL){
            delete next;
        }
    }

};
class hashtable{
    int totsize;
    int currsize;
    node**table;
   public: hashtable(int size = 5){
        totsize=size;
        currsize=0;
        table= new node*[totsize];
        for(int i=0; i<totsize; i++){
            table[i]= NULL;

        }
    };
    int hashfunction(string key){
        int idx=0;
        for(int i=0; i<key.size(); i++){
            idx= (idx+(key[i]*key[i])%totsize)%totsize;
        }
        return idx;
    }
    void rehash(){
        node**oldtable= table;
        int oldsize= totsize;
        totsize= 2*totsize;
        currsize=0;
        table= new node*[totsize];
        for(int i=0; i<totsize; i++){
            table[i]=NULL;
        }
        for(int i=0; i<oldsize; i++){
            node*temp=oldtable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }
            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
        delete[] oldtable;
    }
    void insert(string key, int val){
        int idx= hashfunction(key);
        node* newnode= new node (key, val);
        
        newnode->next=table[idx];
        table[idx]=newnode;
        currsize++;
        double lambda= currsize/(double)totsize;
        if(lambda>1){
            rehash();
        }

    }
    bool exists(string key){
        int idx= hashfunction(key);
        node*temp= table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    int search(string key){
         int idx=hashfunction(key);
        node*temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }
    void print(){
        for(int i=0; i<totsize; i++){
            node*temp=table[i];
            while(temp!=NULL){
                cout<<temp->key<<"->"<<temp->val<<endl;
                temp=temp->next;
            }

        }
    }
    void remove(string key){
        int i=hashfunction(key);
        node*temp=table[i];
        node*prev=temp;
        while(temp!=NULL){
            if(temp->key==key){
                if(prev==temp){
                    table[i]=temp->next;
                }
                else{
                    prev->next=temp->next;
                }
                break;
                
            }
            prev=temp;
            temp=temp->next;
        }

    }
    //on average constant timp complexity
};



int main(){
hashtable ht;
ht.insert("India",150);
ht.insert("china",100);
ht.insert("canada",250);
ht.insert("nepal",15);
ht.insert("bhutan",80);
ht.insert("uk",100);
if(ht.exists("India")){
    cout<<"India population="<<ht.search("India")<<endl;
    ht.remove("canada");
    ht.print();;

}return 0;








    
}