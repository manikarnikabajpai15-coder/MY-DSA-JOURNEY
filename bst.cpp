/*BINARY SEARCH TREE
   THE PROPERTIES-> LEFT SUBTREE<NODE
                     RIGHT SUBTREE>NODE
                     INORDER TRAVERAL OF BST IS A SORTED SEQUENCE*/
#include<iostream>
#include<vector>
using namespace std;
class node{
public:
int data;
node*left=NULL;
node*right=NULL;
node(int data){
   this->data= data;
   left=right=NULL;
};};
node* insert(node*root,int val){
   if(root==NULL){
      root= new node(val);
      return root;
   }
   if(val<root->data){
      root->left= insert(root->left,val);
   }
   else{root->right=insert(root->right,val);};
   return root;
};
node* buildbst(int arr[],int n){

   node* root=NULL;
   for(int i=0; i<n; i++){
      root=insert(root,arr[i]);
   };
return root;
};
void inorder(node*root){
   if(root==NULL){
      return;
   }
   inorder(root->left);
   cout<<root->data;
   inorder(root->right);
};
bool search(node*root,int key){
   if(root==NULL){
      return false;
   };
   if(root->data==key){
      return true;
   }
   else if(root->data>key){
      return search(root->left,key);
   }
   else{return search(root->right,key);};
   return false;
}
node* search_key(node*root,int key){
   if(root==NULL){
      return NULL;
   };
   if(root->data==key){
      return root;
   }
   else if(root->data>key){
      return search_key(root->left,key);
   }
   else{return search_key(root->right,key);};
   return NULL;
}
node* inorder_succ(node*root){
   while(root->left!=NULL){
      root= root->left;
   }
   return root;
};
/*deleting a node cases
for deleting a node firstly search that node and when we found that node
there will ve three cases 
1. root have no child (leaf node)
->simply delete node and return null
2. root have exactly one child
->return its child 
3.root have two children
-> replace the value of root with its inorderer succesor
and then delete the inorder succesor node */
node* delnode(node*root1, int key){
  node* root= search_key(root1,key);
  if(root->left==NULL && root->right==NULL){
   delete root;
   return NULL;
  }
else if(root->left!=NULL || root->right!=NULL){
   if(root->left!=NULL){
      return root->left;
   }
   else{return root->right;};
}
else{
root->data= inorder_succ(root->right)->data;
root->right = delnode(root->right,inorder_succ(root->right->data));
return root;
};

}
int main(){
   int arr[6]={8,4,7,2,5,1};
   int n=6;
node* root= buildbst(arr,6);
inorder(root);
delnode(root,7);
inorder(root);
   return 0;
}
