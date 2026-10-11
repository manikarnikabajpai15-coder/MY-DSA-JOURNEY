#include <iostream>
#include <string>
using namespace std;
bool isanagram(string str1 , string  str2)
{
    if(str1.length() != str2.length()){
        cout<<"not a valid anagram";
        return false;
    }
    int count[26]={0};
    for(int i=0; i<str1.length(); i++){
        int idx= str1[i]-'a';
        count[idx]++;
}
for(int i=0; i<str2.length(); i++)
{int idx= str2[i]-'a';
if (count[idx]==0){
    cout<<"not a valid anagram";
    return false;
}
count[idx]--;}
    cout<<"valid anagram";
    return true;
}

int main() {
    string str1 = "anagram";
    string str2 = "nagaram";
    isanagram(str1, str2);
    return 0;
	

}
