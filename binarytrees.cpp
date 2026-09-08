#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data= data;
        left =right= NULL;
    };
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
    void pre_order(node* root){
        if(root==NULL){
            return;
        };
        cout<<root->data<<endl;
        pre_order(root->left);
        pre_order(root->right);
    };
    void in_order(node*root){
        if(root==NULL){
            return;
        };
        
        
        in_order(root->left);
        cout<<root->data<<" ";
        in_order(root->right);

    };
    void post_order(node*root){
        if(root==NULL){
            return;
        };
        in_order(root->left);
        in_order(root->right);
        cout<<root->data<<" ";
    };
    void tree_traversal(node*root){
        if(root==NULL){
            return;
        }
        queue<node*> q;
        if(root!=NULL){
            q.push(root);};
            while(!q.empty()){
                node* curr=q.front();
                cout<<curr->data<<" ";
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);}
                    if(curr->right!=NULL){
                        q.push(curr->right);
                    }
                

                
            }
            cout<<endl;

        
    }
    int height(node* root){
if(root==NULL){
    return 0;
}
int lheight= height(root->left);
int rheight= height(root->right);
int currheight= max(lheight,rheight) + 1;
return currheight;
    }
    int count(node* root){
        if(root== NULL){
            return 0;
        };
        int lcount= count(root->left);
        int rcount= count(root->right);
        return lcount+rcount+1;
    };
    int sum(node* root){
        if(root== NULL){
            return 0;
        };
        int lsum= sum(root->left);
        int rsum= sum(root->right);
        return lsum+rsum+root->data;
    };


};
int node::idx=-1;
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node obj(0);
    node*root= obj.build_tree(nodes);
    obj.tree_traversal(root);
    cout<<endl;
    cout<<obj.height(root)<<endl;
    cout<<obj.sum(root);
    



}
