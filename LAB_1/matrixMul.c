#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "validations.c"
#include "matrixOperations.c"
#define BUFFSIZE 256

int main(){

	
	int m1d1,m1d2,m2d1,m2d2;
	printf("Enter Matrix 1 dimensions\n");
	int *dim=readDimensions();
	m1d1=dim[0];
	m1d2=dim[1];

	
	printf("Enter Matrix 2 dimensions\n");
	dim=readDimensions();
	m2d1=dim[0];
	m2d2=dim[1];
	
	if(m1d2!=m2d1){
		printf("Matrix multiplication not possible\n");
	}else{

		int ** m1=readMatrixValues(m1d1,m1d2);
		int ** m2=readMatrixValues(m2d1,m2d2);
		printf("Matrix 1:\n");
		printMatrix(m1d1,m1d2,m1);
		printf("Matrix 2:\n");
		printMatrix(m2d1,m2d2,m2);
		int ** result = multiplyMatrix(m1d1,m2d2,m1d2,m1,m2);
		printf("Result:\n");
		printMatrix(m1d1,m2d2,result);

	}

	return 0; 	
}