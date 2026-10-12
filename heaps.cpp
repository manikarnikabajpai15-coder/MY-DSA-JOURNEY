/*HEAPS/PRIORITY QUEUE
IT IS THE KIND OF QUEUE IN WHICH WE SORT ELEMENTS IN A QUEUE ACCORDING 
TO THE PRIORITY
IT IS PREFERRED OVER SORTING BECAUSE THE TIME COMPLEXITY OF HEAPS ARE
LESSER THAN SORTING 
TIME COMPLEXITY OF HEAPS IS N+ KLOGN*/
#include<iostream>
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

    return 0;
}
