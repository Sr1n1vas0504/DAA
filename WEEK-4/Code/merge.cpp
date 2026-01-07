//ch.sc.u4cse24146
#include <stdio.h>
#include <stdlib.h>

int arr[] = {157,110,147,122,111,149,151,141,123,112,117,133};

void merge(int arr[],int start,int end){
	int mid = (start + end)/2;
	int n1 = mid - start + 1 ;
	int n2 = end - mid;
	int temp1[n1],temp2[n2];
	
	for(int i=0;i<n1;i++){
		temp1[i] = arr[start+i];
	}
	for(int i=0;i<n2;i++){
		temp2[i] = arr[mid+i+1];
	}
	int i=0,j=0;
	int k = start;
	while(i<n1 && j<n2){
		if(temp1[i]>temp2[j]){
			arr[k++] = temp2[j++];
		}
		else{
			arr[k++] = temp1[i++];
		}
	}
	
	while(i<n1){
		arr[k++] = temp1[i++];
	}
	while(j<n2){
		arr[k++] = temp2[j++];
	}
}


void recursion (int arr[] , int start , int end ){
	if(start < end ){ 
		int mid = (start + end)/2;
		recursion(arr,start,mid);
		recursion(arr,mid+1,end);
		merge(arr,start,end);
	}
}

int main(){
	recursion(arr,0,11);
	 for (int i = 0; i < 11; i++)
        printf("%d ", arr[i]);
}
