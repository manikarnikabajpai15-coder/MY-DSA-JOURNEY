//activity selection approach->
//sort activities on the basis of their end time
//start a loop from 0 to n and select all nonoverlapping activities
//overlapping condition-> 1st end>2nd start
// nonoverlapping condition-> 1st end<=2nd start
/*#include<bits/stdc++.h>

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
};
bool compare(pair<int,int> p1, pair<int,int>p2){
    return p1.second<p2.second;
}
int main(){
    vector<int> start={1,3,0,5,8,5};
    vector<int> end={2,4,6,7,9,9};
    cout<<maxActivities(start,end);
    vector<int> start={0,1,2};
    vector<int> end={9,2,4};
    vector<pair<int,int>> activity(3,make_pair(0,0));
    activity[0]= make_pair(0,9);
    activity[1]= make_pair(1,2);
    activity[2]= make_pair(2,4);
    for(int i=0; i<activity.size(); i++){
        cout<<i<<":"<<activity[i].first<<","<<activity[i].second<<endl;
    };
    cout<<"after sorting------";
    sort(activity.begin(),activity.end(),compare);
    for(int i=0; i<activity.size(); i++){
        cout<<i<<":"<<activity[i].first<<","<<activity[i].second<<endl;
        

    };
 return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> p1, pair<int,int>p2){
    return p1.first>p2.first;
};
int fractional_knapsnack(vector<int> val, vector<int> wt, int w){
    int n= val.size();
    int ans=0;
    vector<pair<double,int>> ratio(n, make_pair(0.0,0));
    for(int i=0; i<n; i++){
        double r = val[i]/(double) wt[i];
        ratio[i]= make_pair(r,i);
    };
    sort(ratio.begin(), ratio.end(), compare);
    for(int i=0; i<n; i++){
        int idx= ratio[i].second;
    
        if(wt[idx]<=w){
            ans+= val[idx];
            w-= wt[idx];}
            else{
                ans+= ratio[i].first* w;
            };};
return ans; }
int main(){
    vector<int>val= {60,100,120};
    vector<int>wt= {10,20,30};
    int w= 50;
    cout<<fractional_knapsnack(val,wt,w);

    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int min_absdiff(vector<int>a, vector<int>b){
    int ans=0;
    int n= a.size();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<pair<int,int>> c(n,make_pair(0,0));
    for(int i=0; i<n; i++){
        c[i]=make_pair(a[i],b[i]);
    };
    for(int i=0; i<n; i++){
ans+= abs(c[i].first - c[i].second);
    };
    return ans;

}
int main(){
    vector<int> a={4,1,8,7};
    vector<int> b={2,3,6,5};
    cout<<min_absdiff(a,b);
    return 0
}*/
#include<bits/stdc++.h>
using namespace std;
void get_change(vector<int>coins, int v){
int n= coins.size();
int ans=0;
for(int i=n-1; i>=0 && v>0; i--){
    if(v>=coins[i]){
        ans+=v/coins[i];
        v=v%coins[i];
cout<<ans<<"coins of"<<coins[i]<<endl;
ans=0;
    };
    

};
}
int main(){
    vector<int>coins= {1,2,5,10,20,50,100,500,2000};
    int v= 590;
get_change(coins,v);
    return 0

cout<<endl;
    return 0;

}
