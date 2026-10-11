#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(char word[], int n){
    int st =0; int end =n-1;
    while(st<end){
        if(word[st]!=word[end]){
            cout<<"not a valid palindrome";
            return false;
        }
        
        st++;
        end--;
        
    }cout<<" valid palindrome";
    return true;
}

int main(){
    char word[]="racecar";
    ispalindrome(word, strlen(word));
    
    return 0;
}