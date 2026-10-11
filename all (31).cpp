#include <bits/stdc++.h>
using namespace std;
int fo(vector<int> arr, int i, int target){
    if(i==arr.size()){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    return fo(arr,  i+1, target);
}

int main() {
    vector<int> arr={1,2,3,3,5};
    cout<<fo(arr, 0, 3);
    return 0;
	

}
