#include<iostream>
#include<iterator>
#include<list>
using namespace std;

int main(){
list<int> ll;
ll.push_front(2);
ll.push_front(1);
ll.push_back(3);
ll.push_back(5);
list<int>::iterator itr;
for(itr= ll.begin(); itr!=ll.end(); itr++){
cout<<(*itr);
}
cout<<ll.size();


    return 0;
}
