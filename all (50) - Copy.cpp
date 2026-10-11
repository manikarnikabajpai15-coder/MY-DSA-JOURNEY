#include <bits/stdc++.h>
using namespace std;
int fo(int arr[], int i,int n, int target){
    if(arr[i]==target){
        return i;
    }
    return fo(arr, i+1 , n, target);}
    

int main() {
	int arr[5]={1,6,3,4,5};
cout<<fo(arr,0,5,4);
	return 0;

}
