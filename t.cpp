#include<iostream>
using namespace std;
class node{
public:
int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }

    

}
static int idx;
    node* build_tree(vector<int> nodes){
        idx++;
        if(nodes[idx]==-1){
            return NULL;

        };
        node* currnode= new node(nodes[idx]);
        currnode->left= build_tree(nodes);
        currnode->right= build_tree(nodes);
        return currnode;
    };
int main(){
    return 0;
}