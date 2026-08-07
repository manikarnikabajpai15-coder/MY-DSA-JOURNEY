#include <bits/stdc++.h>
#include <string>
using namespace std;
void permutations(string str , string ans){
    int n= str.size();
    if(str.size()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<str.size(); i++){
        char ch= str[i];
permutations((str.substr(0,i))+ (str.substr(i+1, n-i-1)), ans + ch);
    }
}

int main() {
	string str = "abc";
	string ans = "";
	permutations(str , ans);
	return 0;

}
