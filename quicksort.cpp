#include <bits/stdc++.h>
using namespace std;


	void printarr(int arr[], int n){
	    for(int i=0; i<n; i++){
	        cout<<arr[i];
	    }}
	    int partition(int arr[],int si, int ei){
	        int i= si-1;
	        int pivot= arr[ei];
	        for(int j=si; j<ei; j++){
	            if(arr[j]<=pivot){
	                i++;
	                int temp=arr[i];
	                arr[i]=arr[j];
	                arr[j]=temp;
	            }
	        } int temp= arr[i+1];
	        arr[i+1]=arr[ei];
	        arr[ei]=temp;
	        return i+1;
	    }
	    void quicksort(int arr[], int si, int ei){
	        if(si>=ei){
	            return;
	        }
	        int pivotidx= partition(arr, si, ei);
	        quicksort(arr,si,pivotidx-1);
	        quicksort(arr,pivotidx +1, ei);
	    }
	
	int main(){
	    int n=6;
	    int arr[]={6,2,8,1,7,4};
	    quicksort (arr,0,5);
	    printarr(arr,6);
	    return 0;
	    
	
	
	
	

}
