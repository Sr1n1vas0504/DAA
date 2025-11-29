//ch.sc.u4cse24146
#include<stdio.h>

int main(){
	int mat[3][3]={ {1,2,3},{4,5,6},{7,8,9} };
	int newmat[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			newmat[i][j] = mat[j][i];
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d\t",newmat[i][j]);
		}
	printf("\n");
	}
}

