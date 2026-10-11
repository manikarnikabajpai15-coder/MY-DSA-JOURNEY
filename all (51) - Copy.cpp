#include <bits/stdc++.h>
using namespace std;
bool ifsorted(int arr[], int n, int i){
    if(i==n-1){
        return true;}
        if(arr[i]>arr[i+1]){
            return false;
        }
        return ifsorted(arr,  n,  i+1);
        
        
    
}

int main() {
	int arr[5]={1,6,3,4,5};
cout<<ifsorted(arr, 5,0 );
	return 0;

}
