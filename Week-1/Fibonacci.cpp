//ch.sc.u4cse24146
#include<stdio.h>
int n;

int main(){
	printf("Enter Number :");
	scanf("%d",&n);
	int num1 = 0;
	int num2 = 1;
	int num3;
	printf("%d %d ",num1,num2);
	for(int i=2;i<n;i++){
		num3 = num1 + num2;
		printf("%d ",num3);
		num1 = num2;
		num2 = num3;
	}
}


