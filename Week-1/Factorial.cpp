//ch.sc.u4cse24146
#include <stdio.h>

int fac(int n){
	if(n==0 || n==1){
		return 1;
	}
	else{
		return n*fac(n-1);
	}
}

int main(){
	int n;
	printf("Enter a num :");
	scanf("%d",&n);
	printf("The factorial of N is: ");
	printf("%d\n",fac(n));
}

