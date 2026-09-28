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
int main(){
   int arr[6]={8,4,7,2,5,1};
   int n=6;
node* root= buildbst(arr,6);
inorder(root);
cout<<endl;
   return 0;
}
