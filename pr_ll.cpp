#include<iostream>
using namespace std;
struct node
{
    int coeff;
    int exp;
    node*next;
};
int main(){
    node*poly1= NULL;
    node*poly2= NULL;
    insert(poly1,5,2);
    insert(poly1, 4,1);
    insert(poly1, 2,0);
    insert(poly2, 3,2);
    insert(poly2, 2,1);
    insert(poly2, 1,0);

}
