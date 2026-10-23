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
using namespace std;
class graph{
    int v;
    list<int> *l;
    public:
    graph(int v){
        this->v= v;
        l= new list<int> [v];
    };

void addEdge(int p, int q){
    l[p].push_back(q);
    l[q].push_back(p);

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
void dfs(int u, vector<bool> &visi){
    visi[u]=true;
    cout<<u<<" ";
    list<int> neighbours= l[u];
    for(int i: neighbours){
        if(!visi[i]){
            dfs(i,visi);
        };
    };

};};
int main(){
    graph g(5);
    vector<bool> visi(5,false);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(1,3);
g.addEdge(2,3);
g.addEdge(2,4);
g.dfs(0,visi);
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
