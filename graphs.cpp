//GRAPH->IS A CONNECTION OF NODES
/*THERE ARE DIFFERENT KIND OF GRAPHS 
-> 1. UNIDIRECTED-> IN WHICH THE DIRECTION IS GOINT TO ONE SIDE ONLY
UNDIRECTED/BIDIRECTED-> IN WHICH THE DIRECTION S GOING TO BOTH SIDES
WEIGHTED-> WHEN THERE ID A VALUE ASSOCIATED WITH EDGES OR PATHS JOINING TWO NODES
UNWEIGHTED-> WHEN THERE IS NO VALUE ASSOCIATED 
THERE ARE DIFFERENT WAYS FOR STORING A GRAPH
->ADJACENT LIST
->ADJACENT MATRIX
->EDGE LIST
->2D MATRIX(IMPLICIT GRAPH)
IN GRAPH USING ADJACENT LIST-> WE STORE NEIGHBOURS OF EACH VERTICES IN A
SEPERATE LIST AND THEN WE STORE ALL THE LISTS IN AVECTOR OF LISTS.
IT IS PACE OPTIMIZED AND NEIGHBOUR OPTIMIZED.
IN GRAPHS USING ADJACENT MATRIX -> IF THERE ARE V VERTICES THEN WE MAKE V*V MATRIX
AND IF G[U][V]=0-> IT MEANS THAT THERE IS NO WAY FROM U TO V
IF G[U][V]=1 -> IT MEANS THAT THERE IS A WAY FROM U TO V
IT IS NOT NEIGHBOUR OPTIMIZED AND SPACE OPTIMIZED.
EDGE LIST-> THE LIST OF EDGES IN FORM OF VECTORS OR LISTS 
IF THERE ARE TWO TERMS GIVEN LIKE U AND V THEN WE WILL MAKE PAIR
BUT IF THERE ARE THREE TERMS THEN WE WILL MAKE CLASS AND THEN MAKE VECTOR OF THAT CLASS. */
//ADJACENCY LIST->unweighted
#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<string>
using namespace std;
class graph{
    int v;
    list<int> *l;
    bool isundir;
    public:
    graph(int v, bool isundir=true){
        this->v= v;
        this->isundir=isundir;
        l= new list<int> [v];

    };

void addEdge(int p, int q){
    l[p].push_back(q);
    if(isundir){
    l[q].push_back(p);}

};
void print(){
    for(int i=0; i<v; i++){
        list<int> neighbours= l[i];
        cout<<i<<":";
        for(int u:neighbours){
            cout<<u<<" ";
        };
        cout<<endl;
    };
};
void bfs(){
queue<int> q;
vector<bool> visi(v,false);
q.push(0);
visi[0]=true;
while(q.size()>0){
    int u= q.front();
    q.pop();
    cout<<u<<" ";
    list<int> neighbours= l[u];
    for(int i:neighbours){
        if(!visi[i]){
            visi[i]=true;
            q.push(i);
        };
    };
};

};
void dfshelper(int u, vector<bool> &visi){
    
    visi[u]=true;
    cout<<u<<" ";
    list<int> neighbours= l[u];
    for(int i: neighbours){
        if(!visi[i]){
            dfshelper(i,visi);
        };
    };

};
void dfs_disjoint(){
    vector<bool> vis(v,false);
    for(int i=0; i<v; i++){
        if(!vis[i]){
         dfshelper(i,vis);};
         cout<<endl;
}};

void dfs(){
    vector<bool> vis(v,false);
         dfshelper(0,vis);
         cout<<endl;
};
bool pathhelper(int src, int des, vector<bool> &visited){
    if(src==des){
        return true;
    }
    visited[src]= true;
    list<int> neighbours= l[src];
    for(int i: neighbours){
        if(!visited[i]){
        if(pathhelper(i,des,visited)){
            return true;
        }
    }

    }
    return false;
}
bool has_path(int src, int des){
    vector<bool> visited(v,false);
    return pathhelper(src,des,visited);
}
//cycle in graphs
/*cycle detection:-
 undirected-> algorithms->
 ->bfs
 ->dfs
 ->disjoint set union
 directed-> algorithms->
 ->bfs
 ->dfs
 ->kahns algorithms(topological) 
           */
bool undircycle_help(int src, int par, vector<bool> vis){
    vis[src]= true;
    list<int> neighbours= l[src];
    for(int i: neighbours){
if(!vis[i]){
    if(undircycle_help(i,par,vis)){
    return true;}
    else{
        if(i!=par){
            return true;
        };
    };

};
    }
    return false;
};
bool iscycleundir(){
    vector<bool>vis(v,false);
   return undircycle_help(0,-1,vis);
};
/*the edge which connects src and the neighbour which is not parent is called back edge.*/
bool cycledirhelp(int src, vector<bool> &vis, vector<bool> &recpath){
    vis[src]= true;
    recpath[src]= true;
    list<int> neighbours= l[src];
    for(int i: neighbours){
if(!vis[i]){
    if(cycledirhelp(i,vis,recpath)){
        return true;
    }}
    else{
        if(recpath[i]){
            return true;
        };
    };
}
    
    recpath[src]= false;
    return false;

};
bool iscycledir(){
        vector<bool> vis(v,false);
        vector<bool> recpath(v,false);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                if(cycledirhelp(i,vis,recpath)){
                    return true;
                }
            }
        }
        return false;
    };
    // Bipartite graph->no edge connect vertices of same path
bool bipartite(){
    queue<int> q;
    
    vector<int> color(v,-1);
    q.push(0);
    color[0]=0;
    while(q.size()>0){
        int curr= q.front();
        q.pop();
        list<int> neighbours= l[curr];
        for(int i: neighbours){
            if(color[i]==-1){
                color[i]=!color[curr];
                q.push(i);
            }
            else{
                if(color[i]==color[curr]){
                    return false;
                }
            };
        };

    };
    return true;

}
/*
bipartite conditions:-
1-> the coloring condition
2->if the graph is acyclic then it will be a bipartite graph
3->if the cycle is even the in will be a bipartite
4-> if the cycle is odd then it will not be a bipartite*/
bool bipartite2(int n){

    if(!iscycleundir()){
        return true;
    }
    else{
        if(n%2==0){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
};
void pathhelper(int src, int des, vector<bool> &vis, string &path){
    if(src==des){
        cout<<path<<des<<endl;
        return;
    };
    vis[src]= true;
    path+=to_string(src);
    list<int> neigbours= l[src];
    for(int i: neigbours){
        if(!vis[i]){
            pathhelper(i,des,vis,path);
        };
    };
    path= path.substr(0,path.size()-1);
    vis[src]=false;

};
void allpaths(int src, int des){
    vector<bool> vis(v,false);
    string path= "";
    pathhelper(src,des,vis,path);
};

};
int main(){
    graph g(6,false);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.allpaths(5,1);

    return 0;
}
//adjacency list->weighted
/*#include<iostream>
#include<list>
#include<vector>
using namespace std;
class graph{
    int v;
    list<pair<int,int>> *l;
    public:
    graph(int v){
        this->v= v;
        l= new list<pair<int,int>> [v];
    };
    void addEdge(int p,int q,int w){
l[p].push_back(make_pair(q,w));
l[q].push_back(make_pair(p,w));
    };
    void print(){
        for(int i=0; i<v; i++){
            cout<<i<<":";
            list<pair<int,int>> neighbours= l[i];
            for(pair<int,int> u:neighbours){
cout<<"("<<u.first<<","<<u.second<<")"<<" ";
            }
            cout<<endl;
        };
    };
    
        
    
};
int main(){
    graph g(5);
    g.addEdge(0,1,2);
g.addEdge(1,2,7);

g.addEdge(1,3,-1);
g.addEdge(2,3,4);
g.addEdge(2,4,0);
g.print();
    return 0;
}*/
// Bipartite graph->no edge connect vertices of same path
