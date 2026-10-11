#include <bits/stdc++.h>
using namespace std;
int tiling(int n){
    if(n==0||n==1){
        return 1;
    }
  int answer1= tiling(n-1); //vertical
  int answer2= tiling(n-2);//horizontal
  return answer1+ answer2;
}

int main() {
	// your code goes here
	cout<<tiling(4);
	return 0;

}
