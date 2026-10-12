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

node* delnode(node* root, int key) {

    if (root == NULL) {
        return NULL;
    }

    // Search for the node
    if (key < root->data) {
        root->left = delnode(root->left, key);
    }

    else if (key > root->data) {
        root->right = delnode(root->right, key);
    }

    // Node found
    else {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Only left child
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Only right child
        else if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else {
            node* succ = inorder_succ(root->right);

            root->data = succ->data;

            root->right = delnode(root->right, succ->data);
        }
    }

    return root;
}
void printInRange(node*root, int v1,int v2){
   if(root==NULL){
      return;
   }
   if(root->data>=v1 && root->data<=v2){
      cout<<root->data<<" ";
      printInRange(root->left,v1,v2);
      printInRange(root->right,v1,v2);}
      else if(root->data<v1){
         printInRange(root->right,v1,v2);
      }
      else if(root->data>v2){
         printInRange(root->left,v1,v2);
      };}
      node* arr_to_bst(vector<int>& arr, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;

    node* root = new node(arr[mid]);

    root->left = arr_to_bst(arr, left, mid - 1);
    root->right = arr_to_bst(arr, mid + 1, right);

    return root;
}

void inorder1(node* root, vector<int>& arr) {
    if (root == NULL) {
        return;
    }

    inorder1(root->left, arr);
    arr.push_back(root->data);
    inorder1(root->right, arr);
}

node* bst_to_balbst(node* curr) {
    vector<int> v;

    // Step 1: Store BST elements in sorted order
    inorder1(curr, v);

    // Step 2: Build a balanced BST
    node* root = arr_to_bst(v, 0, (int)v.size() - 1);

    return root;
}
class info{
   public:
   bool isbst;
   int max;
   int min;
   int sz;
   info(bool isbst, int max, int min, int sz){
      this->isbst= isbst;
      this->max= max;
      this->min=min;
      this->sz=sz;
   }
};
static int maxsize=0;
info* largestBst(node*root){
   
   if(root==NULL){
      return new info(true,INT_MIN,INT_MAX,0);
   };
   info* leftinfo= largestBst(root->left);
   info* rightinfo= largestBst(root->right);
   int currMin= min(root->data,min(leftinfo->min,rightinfo->min));
   int currMax= max(root->data,max(leftinfo->max,rightinfo->max));
   int currsz= leftinfo->sz + rightinfo->sz+ 1;
if(leftinfo->isbst && rightinfo->isbst && root->data>leftinfo->max &&
root->data<rightinfo->min){
   maxsize= max(maxsize,currsz);
   return new info(true,currMax,currMin,currsz);
   
}

return new info(false,currMax,currMin,currsz);

}
node*merge_bst(node*root1,node*root2){
   vector<int>a1;
   vector<int>a2;
   vector<int>merged;
   inorder1(root1,a1);
   inorder1(root2,a2);
   int i=0; int j=0;
   while(i<a1.size() && j<a2.size()){
      if(a1[i]<a2[j]){
merged.push_back(a1[i++]);
      }
      else{merged.push_back(a2[j++]);};
   };
   while(i<a1.size()){
      merged.push_back(a1[i++]);
   };
   while(j<a2.size()){
      merged.push_back(a2[j++]);
   };
   return arr_to_bst(merged,0,merged.size()-1);}
   




 int main(){
   node* root1= new node(2);
    root1->left= new node(1);
    root1->right= new node(4);
    node* root2= new node(9);
    root2->left= new node(3);
    root2->right= new node(12);
    node* root= merge_bst(root1,root2);
    inorder(root);

   return 0;
 }
      
