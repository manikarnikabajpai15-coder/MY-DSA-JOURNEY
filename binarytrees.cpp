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
    
    int dia1(node*root){//o(n^2)
        if(root==NULL){
            return 0;
        }
        int currDia= height(root->left)+ height(root->right)+1;
        int leftDia= dia1(root->left);
        int rightDia= dia1(root->right);
        return max(currDia,max(leftDia,rightDia));
        
    };
    bool is_identical(node*root1, node*root2){
        if(root1==NULL && root2==NULL){
            return true;}
           else if(root1==NULL || root2==NULL){
                return false;
            };
        if(root1->data!=root2->data){
            return false;
        };
        return is_identical(root1->left,root2->left) && is_identical(root1->right,root2->right);
    }
    bool issubtree(node*root, node*subroot){
        if(root==NULL && subroot==NULL){
            return true;}
           else if(root==NULL || subroot==NULL){
                return false;
            };
            if(root->data==subroot->data){
           if (is_identical(root,subroot)){
            return true;
           };
            };
            int isleftsubtree= issubtree(root->left, subroot);
            if(!isleftsubtree){
                return issubtree(root->right, subroot);
            }
return true;
        
    };
    void topview(node*root){
        queue<pair<node*, int>> q;
        map<int,int>m;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<node*,int> curr= q.front();
            q.pop();
        
        node* currNode= curr.first;
        int currhd= curr.second;
        if(m.count(currhd)==0){
            m[currhd]= currNode->data;
        }

    }



};
void khelper(node*root, int k, int currlevel){
    if(root== NULL){
        return;
    }
    if(currlevel==k){
        cout<< root->data<<" ";
        return;
    }
    khelper(root->left,k,currlevel+1);
    khelper(root->right,k,currlevel+1);

}
void klevel(node*root, int k){
    khelper(root,k,1);
    cout<<endl;
    
}

    bool findpath(node* root, int n, vector<int>& path) {
    if (root == NULL) {
        return false;
    }

    path.push_back(root->data);

    if (root->data == n) {
        return true;
    }

    if (findpath(root->left, n, path)) {
        return true;
    }

    if (findpath(root->right, n, path)) {
        return true;
    }

    path.pop_back();   // ye path ka important part hai
    return false;
}

int LCA1(node*root, int n1, int n2){
    int l=-1;
    vector<int> path1;
    vector<int> path2;
    findpath(root,n1,path1);
    findpath(root,n2,path2);
    for(int i=0;i<path1.size();i++){
        for(int j=0;j<path2.size(); j++){
if(path1[i]==path2[j]){
    l=path1[i];;
};
        };
    };
    return l;
};
node* LCA2(node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    };
    node* leftLCA= LCA2(root->left,n1,n2);
    node* rightLCA= LCA2(root->right,n1,n2);
    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }
    return leftLCA==NULL ? rightLCA:leftLCA;
};
int dis(node*root, int n){
    if(root==NULL){
        return -1;
    };
    if(root->data==n){
        return 0;
    };
    int leftdis= dis(root->left,n);
    if(leftdis!=-1){
        return leftdis+1;
    };
    int rightdis= dis(root->right,n);
    if(rightdis!=-1){
        return rightdis+1;
    };
    return -1;

};
int mindis(node*root,int n1,int n2){
    node*lca= LCA2(root,n1,n2);
    int dis1= dis(lca,n1);
    int dis2= dis(lca,n2);
    return dis1+dis2;

};
int kth_ancestor(node*root,int node, int k){
    if(root==NULL){
        return -1;
    };
    if(root->data==node){
        return 0;
    };
    int leftdis= kth_ancestor(root->left,node,k);
    int rightdis= kth_ancestor(root->left,node,k);
if(leftdis==-1 && rightdis==-1){
    return -1;
};
int validval= leftdis==-1 ? rightdis:leftdis;
if(validval+1==k){
    return root->data;
};
return validval+1;
    
};
int sum_tree(node*root){
    if(root==NULL){
        return 0;
    };
    int left_old=sum_tree(root->left);
    int right_old=sum_tree(root->right);
    int currold= root->data;
    root->data=left_old+right_old;
    if(root->left!=NULL){
    root->data+=root->left->data;};
    if(root->right!=NULL){
    root->data+=root->right->data;};

    return currold;

    
}



};

int node::idx=-1;
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node obj(0);
    node*root= obj.build_tree(nodes);
obj.sum_tree(root);
obj.tree_traversal(root);
return 0;





    



}
