//ch.sc.u4cse24146	
#include <stdio.h>
int sumofcube(int n){
	int sum = 0;
	while(n!=0){
		sum+=n*n*n;
		n--;
	}
	return sum;
}

int main(){
	int n;
	printf("Enter a num :");
	scanf("%d",&n);
	printf("The sum of cubes of N natural number: ");
	printf("%d\n",sumofcube(n));
}


