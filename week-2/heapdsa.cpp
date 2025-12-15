//ch.sc.u4cse24146
#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertheap(int arr[],int *n,int value){
	//heapify up 
	*n = *n+1;
	arr[*n]=value;
	int i = *n;
	while(i>1){
		int parent = i/2;
		if(i>=*n && arr[parent]<arr[i]){
			swap(&arr[parent],&arr[i]);
			i = parent;
		}
		else{
			break;
		}
	} 
}

int deleteMax(int arr[],int *n){
	// heapify down
	int max = arr[1];
	arr[1]=arr[*n];
	int i = 1;
	while(1){
		int largest = i;
		int left = 2*i;
		int right = 2*i+1;
		
		if(i<=*n && arr[largest]<arr[left]){
			largest = left;
		}
		if(i<=*n && arr[largest]<arr[right]){
			largest = right;
		}
		if(!largest == i){
			swap(&arr[largest],&arr[i]);
			i = largest;
		}
		else{
			break;
		}
	}
	*n = *n-1;
	return max;
}

void display(int arr[],int *n){
	for(int i=1;i<=*n;i++){
		printf("%d \n",arr[i]);
	}
}

int main() {
   int arr[100];
    int n = 0;

    insertheap(arr, &n, 15);
    insertheap(arr, &n, 8);
    insertheap(arr, &n, 20);
    insertheap(arr, &n, 2);
    insertheap(arr, &n, 30);
	printf("Deleted max: %d\n", deleteMax(arr, &n));
    display(arr, &n);
    printf("Deleted max: %d\n", deleteMax(arr, &n));
    display(arr, &n);
    return 0;
}



