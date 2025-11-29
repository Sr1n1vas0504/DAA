//ch.sc.u4cse24146
#include <stdio.h>
int sumofN(int n){
	int sum = 0;
	while(n!=0){
		sum+=n;
		n--;
	}
	return sum;
}

int main(){
	int n;
	printf("Enter a num :");
	scanf("%d",&n);
	printf("The sum of N natural number: ");
	printf("%d\n",sumofN(n));
}
