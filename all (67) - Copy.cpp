#include <bits/stdc++.h>
using namespace std;
bool staircase(int a[][4], int n, int m, int key){
    int i=0; int j=m-1;
    while(i<n && j>=0){
        if(a[i][j]==key){
            cout<<"founded at("<<i<<","<<j<<")";return true;
        }
        else if(a[i][j]<key){
            i++;
        }else {
            j--;
        }
    }
}

int main() {
	int a[4][4]{{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
	staircase(a, 4,4,33);
	return 0;}
	
