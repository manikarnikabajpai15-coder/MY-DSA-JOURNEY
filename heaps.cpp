/*HEAPS/PRIORITY QUEUE
IT IS THE KIND OF QUEUE IN WHICH WE SORT ELEMENTS IN A QUEUE ACCORDING 
TO THE PRIORITY
IT IS PREFERRED OVER SORTING BECAUSE THE TIME COMPLEXITY OF HEAPS ARE
LESSER THAN SORTING 
TIME COMPLEXITY OF HEAPS IS N+ KLOGN*/
/*#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(20);
    pq.push(10);
    pq.push(5);
    pq.push(7);
    pq.push(2);
    while(!pq.empty()){
        cout<<pq.top()<<"";
        pq.pop();
    };
    cout<<endl;
    priority_queue<int,vector<int>,greater<int>> pqmin;
    pqmin.push(20);
    pqmin.push(10);
    pqmin.push(5);
    pqmin.push(7);
    pqmin.push(2);
    while(!pqmin.empty()){
        cout<<pqmin.top()<<"";
        pqmin.pop();
    };


    return 0;
}*/
/*HEAPS->VISUALIZED AS COMPLETE BINARY TREE AND IMPLENTED BY USING VECTOR
AND ARRAYS AND PRIORITY QUEUE ARE BASED ON THE LOGIC OF HEAPS
CBT->COMPLETE BINARY TREE 
IT IS THE KIND OF BINARY TREE WHERE ALL THE LEVELS ARE FILLED NOT MAY BE THE 
LAST ONE AS IT FILLED FROM LEFT TO RIGHT
PARENT>=CHILDREN->MAX HEAP
PARENT<=CHILDREN->MIN HEAP
PARENT INDEX=i
left child index= 2*i+1;
right child index= 2*i+2;
if children index=x;
then parent index= x-1/2;
*/
/*#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std; 
class heap{
    vector<int> vec;
    public:
    void push(int val){
        vec.push_back(val);
        int x=vec.size()-1;
    int child_idx=x;
    int parent_idx= (x-1)/2;
    
        
        while(parent_idx>=0 && vec[child_idx]>vec[parent_idx]){
            swap(vec[child_idx],vec[parent_idx]);
            x= parent_idx;
            parent_idx= (x-1)/2;
        };}
        void heapify(int i){
            if(i>=vec.size()){
                return;
        }
        int l= 2*i+1;
        int r= 2*i+2;
        int maxidx= i;
        if(l<vec.size() && vec[l]>vec[maxidx]){
            maxidx= l;
        }
        if(r<vec.size() && vec[r]>vec[maxidx]){
            maxidx= r;
        }
        swap(vec[maxidx],vec[i]);
        if(i!=maxidx){
            heapify(maxidx);
    }}

        void pop(){
            swap(vec[0],vec[vec.size()-1]);
            vec.pop_back();
            heapify(0);

        }
        int top(){
            return vec[0];
        }
        bool is_empty(){
            if(vec.empty()){
                return true;
        };
        return false;};
    };
    class student{
        public:
        string name;
        int marks;
        student(string name,int marks){
            this->name=name;
            this->marks=marks;
        }
        bool operator <(const student &obj) const{
            return this->marks<obj.marks;

        }
    };
        int main(){
            priority_queue<student> pq;
            pq.push(student("aman",46));
            pq.push(student("rhiti",78));
            pq.push(student("qazi",89));
            while(!pq.empty()){
                cout<<pq.top().name<<pq.top().marks<<endl;
                pq.pop();
            }
            //for pair in heaps we need to priority_queue<pair<string,int>,vector<pair<string,int>>,compare_pair()> pq;
            //for push it we need to write pq .push(make_pair(.....))
            struct compare_pair{
            bool operator(pair<string,int> &p1, pair<string,int> &p2 ){
            return p1.second<p2.second -> for min heap and vice versa for max heap}}


            return 0;
        }*/
       /*#include<iostream>
       #include<vector>
       #include<queue>
       using namespace std;
       void heapify(int i,vector<int> & arr,int n){
        int left= 2*i+1;
        int right= 2*i+2;
        int maxi =i;
        if(left<n && arr[left]>arr[maxi]){
            maxi=left;
        }
         if(right<n && arr[right]>arr[maxi]){
            maxi=right;
        }
    if(maxi!=i){
        swap(arr[maxi],arr[i]);
        heapify(maxi,arr,n);
    };
    


       }
       void heap_sort(vector<int> & arr){
        int n= arr.size();
        for(int i=n/2-1; i>=0; i--){
            heapify(i,arr,n);
        };
        for(int i=n-1; i>=0; i--){
            swap(arr[0],arr[i]);
            heapify(0,arr,i);
        };
       };
       int main(){
        vector<int> arr= {1,4,2,5,3};
        heap_sort(arr);
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i];
        };
        cout<<endl;
        return 0;
       }*/
      //nearby cars
     /* #include<iostream>
      #include<queue>
      #include<vector>
      using namespace std;
      class car{
        public:
        int idx;
        int distsq;
        
        car(int idx, int distsq){
            this->distsq= distsq;
            this->idx=idx;
        }
        bool operator<(const car &obj) const{
            return this->distsq> obj.distsq;
        };
      };
      void nearby_cars(vector<pair<int,int>> pos,int k){
        vector<car> cars;
for(int i=0; i<pos.size(); i++){
int distsq= (pos[i].first* pos[i].first)+(pos[i].second*pos[i].second);
cars.push_back(car(i,distsq));
}
priority_queue<car> pq(cars.begin(),cars.end());
for(int i=0; i<k; i++){
cout<<"car"<<pq.top().idx<<endl;
pq.pop();
};}
int main(){
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));
    nearby_cars(pos,1);
    return 0;
}*/
//connect n ropes
/*#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int connect_n_ropes(vector<int> ropes){
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(),ropes.end());
int cost=0;
while(pq.size()>1){
    int min1= pq.top();
    pq.pop();
    int min2= pq.top();
    pq.pop();
    cost+=min1+min2;
    pq.push(min1+min2);
};
return cost;


};
int main(){
    vector<int> ropes= {4,3,2,6};
    cout<<connect_n_ropes(ropes);
    return 0;
};*/




      






        

    


