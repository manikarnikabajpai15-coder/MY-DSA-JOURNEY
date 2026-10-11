#include <bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    vector <int>vec={2,7,11,15};
    int target=22;
    int st=0; int end=3;
    while(st<end){
        int currsum = vec[st] + vec[end];
        if (currsum == target){
            cout<<"("<<st<<","<<end<<")";
            break;
        }
        else if(currsum>target){
            end--;
        }
        else{st++;}
        
    }return 0;
}


	        


