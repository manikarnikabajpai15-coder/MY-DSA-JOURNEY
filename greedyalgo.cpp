//activity selection approach->
//sort activities on the basis of their end time
//start a loop from 0 to n and select all nonoverlapping activities
//overlapping condition-> 1st end>2nd start
// nonoverlapping condition-> 1st end<=2nd start
#include<iostream>
#include<vector>
using namespace std;
int maxActivities(vector<int> start, vector<int> end){
    int count=1;
    int currEnd= end[0];
    for(int i=1; i<start.size(); i++){
        if(start[i]>=currEnd){
            count++;
            currEnd=end[i];
        };
        
    };
return count;
}
int main(){
    vector<int> start={1,3,0,5,8,5};
    vector<int> end={2,4,6,7,9,9};
    cout<<maxActivities(start,end);

    return 0;
}